#include <stdio.h>
#include <stdlib.h>
#include <nr.h>
#include <math.h>
//fmin 정의 충돌로 인해 NRs/ansi/other/nr.h의 fmin 헤더를 주석처리
#include <time.h>
//실행시간 측정을 위함

void copy_arrays(float **A_dest, float** b_dest, float **A_src, float **b_src, int n, int m) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            A_dest[i][j] = A_src[i][j];
        b_dest[i][1] = b_src[i][1];
    }
}

//각 방법을 통해 구한 해의 오차를 r = Ax - b를 통해 구하는 함수
float residual_norm(float **A, float *x, float **b, int n, int m) {
    float norm = 0.0f;
    for (int i = 1; i <= n; i++) {
        float sum = 0.0f;
        for (int j = 1; j <= m; j++) 
            sum += A[i][j] * x[j];
        float r = b[i][1] - sum;
        norm += r * r;
    }
    return sqrtf(norm);
}

int main(void) {
    const char *files[3] = { "lineq1.dat", "lineq2.dat", "lineq3.dat" };
    //정확도(오차) 저장용 배열
    float res_gj[3] = { 0.0f, 0.0f, 0.0f };
    float res_lu[3] = { 0.0f, 0.0f, 0.0f };
    float res_svd[3] = { 0.0f, 0.0f, 0.0f };
    //실행시간 저장용 배열
    float time_svd[3] = {0.0f, 0.0f, 0.0f};
    float time_gj[3]  = {0.0f, 0.0f, 0.0f};
    float time_lu[3]  = {0.0f, 0.0f, 0.0f};
    clock_t start, end;

    //mprove() 반복하며 보정되는 근 저장용 배열
    //[문제 번호 - 1][반복 횟수 - 1]
    float res_mpr[3][3] = {0.0f};

    for (int t = 0; t < 3; t++) {

    FILE *fp;
    //행렬 크기 저장용
    int n, m;
    //행렬 A, b
    float **A, **b;

    //LU Decomposition에 필요한 변수들
    int *indx;
    float d;
    float *rhs;

    //SVD에 필요한 변수들
    float *w;
    float **v;
    float *xv;

    //오차 체크용 변수들 -> 추후 배열로 합칠듯
    //float res_gj = 0.0f, res_lu = 0.0f, res_svd = 0.0f;
    float *x_gj = NULL;

    //파일 열기-----------------------------------------
    //"r"은 파일을 읽기 모드로 여는 것 선택 (r/w 등등)
    fp = fopen(files[t], "r");
    if (!fp) {
        printf("파일을 열 수 없습니다.\n");
        exit(1);
    }

    //행렬 크기 읽기
    fscanf(fp, "%d %d", &n, &m);

    //A, b 초기화 
    A = (float **)malloc((n + 1) * sizeof(float *));
    for (int i = 1; i <= n; i++) 
        A[i] = (float *)malloc((m + 1) * sizeof(float));
    b = (float **)malloc((n + 1) * sizeof(float *));
    for (int i = 1; i <= n; i++) 
        b[i] = (float *)malloc(2 * sizeof(float));

    //각 함수에 집어넣을 복사본 생성
    float **A_copy = (float **)malloc((n + 1) * sizeof(float *));
    float **b_copy = (float **)malloc((n + 1) * sizeof(float *));
    for (int i = 1; i <= n; i++) {
        A_copy[i] = (float *)malloc((m + 1) * sizeof(float));
        b_copy[i] = (float *)malloc(2 * sizeof(float));
    }

    //A, b 값 입력
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            //정수형으로 저장되어 있지만 A, b가 float 배열이라 %f로 바꿔서 저장
            fscanf(fp, "%f", &A[i][j]);
        
    for (int i = 1; i <= n; i++) 
        fscanf(fp, "%f", &b[i][1]);

    //LU 변수에 동적할당
    indx = (int *)malloc((n + 1) * sizeof(int));
    rhs = (float *)malloc((n + 1) * sizeof(float));

    //SVD 변수에 동적할당
    w = (float *)malloc((n + 1) * sizeof(float));  
    v = (float **)malloc((n + 1) * sizeof(float *));  
    for(int i = 1; i <= n; i++)
        v[i] = (float *)malloc((n + 1) * sizeof(float));
    xv = (float *)malloc((n + 1) * sizeof(float));

    //파일 닫기-----------------------------------------
    fclose(fp);
    
    
    printf("\nMatrix A and vector b loaded:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            printf("%6.2f ", A[i][j]);
        printf("| %6.2f\n", b[i][1]);
    }  
     
    /*
    //SVD 
    copy_arrays(A_copy, b_copy, A, b, n, m);
    for (int i = 1; i <= n; i++) rhs[i] = b_copy[i][1];

    svdcmp(A_copy, n, n, w, v);

    // 작은 특이값 처리
    float threshold = 1.0e-6;  // 임계값 설정
    for(int i = 1; i <= n; i++) {
        if(w[i] < threshold) {
            printf("Small singular value found: w[%d] = %e\n", i, w[i]);
            w[i] = 0.0;
        }
    }
    */

    // ===== SVD (with singularity check) =====
    copy_arrays(A_copy, b_copy, A, b, n, m);
    for (int i = 1; i <= n; i++) rhs[i] = b_copy[i][1];

    //실행시간 시작
    start = clock();

    svdcmp(A_copy, n, n, w, v);   // A_copy -> U

    // 상대 임계값으로 판정 (권장)
    float wmax = 0.0f;
    for (int i = 1; i <= n; i++) if (w[i] > wmax) wmax = w[i];
    float tol = wmax * 1.0e-6f;    // 필요 시 1e-8~1e-12로 조절

    // 랭크 계산 + 작은 특이값 0으로 처리
    int   rank   = 0;
    float wminnz = 1e30f;          // cond 계산용 (양의 특이값 중 최소)
    for (int i = 1; i <= n; i++) {
        if (w[i] > tol) {
            rank++;
            if (w[i] < wminnz) wminnz = w[i];
        } else {
            printf("Small singular value: w[%d] = %e -> set to 0\n", i, w[i]);
            w[i] = 0.0f;
        }
    }

    // 상태 출력 (full rank vs singular/rank deficient)
    if (rank == n) {
        // 조건수(대략) 정보 출력
        printf("\n[SVD] full rank (n=%d). cond ≈ %.3e\n", n, wmax / wminnz);
    } else {
        printf("\n[SVD] singular or rank-deficient: rank %d/%d\n", rank, n);
        // 원하면 여기서 null-space(V의 w==0 열)도 출력 가능
        // for (int k = 1; k <= n; k++) if (w[k] == 0.0f) { ... v[1..n][k] ... }
    }

    // 최소노름 해 계산
    svbksb(A_copy, w, v, n, n, rhs, xv);

    //실행시간 종료
    end = clock();

    time_svd[t] = 1000.0f * (end - start) / CLOCKS_PER_SEC;

    printf("\nSVD Solution x (minimum-norm if singular):\n");
    for (int i = 1; i <= n; i++)
        printf("%8.4f\n", xv[i]);

    //오차 계산 및 출력
    res_svd[t] = residual_norm(A, xv, b, n, m);
    //printf("[SVD] Residual norm = %.3e\n", res_svd);

    /*
    svbksb(A_copy, w, v, n, n, rhs, xv);

    printf("\nSVD Solution x:\n");
    for (int i = 1; i <= n; i++)
        printf("%8.4f\n", xv[i]);
    */

    if (rank == n) {

    //GAUSS-JORDAN
    /*
    copy_arrays(A_copy, b_copy, A, b, n, m);

    start = clock();
    gaussj(A_copy, n, b_copy, 1);
    end = clock();
    
    time_gj[t] = 1000.0f * (end - start) / CLOCKS_PER_SEC;
    */
    int reps = 1000;

    start = clock();
    for (int r = 0; r < reps; r++) {
        copy_arrays(A_copy, b_copy, A, b, n, m);
        gaussj(A_copy, n, b_copy, 1);
    }
    end = clock();
    time_gj[t] = (1000.0f * (end - start) / CLOCKS_PER_SEC )/ reps;

    printf("\nGauss-Jordan Solution x:\n");
    for (int i = 1; i <= n; i++)
        printf("%8.4f\n", b_copy[i][1]); 

    //오차 구할 때 집어넣을 x 명시적 선언
    x_gj = (float *)malloc((n + 1) * sizeof(float));
    for (int i = 1; i <= n; i++) 
        x_gj[i] = b_copy[i][1];
    
    //오차 계산 및 출력
    res_gj[t] = residual_norm(A, x_gj, b, n, m);
    //printf("[Gauss-Jordan] Residual norm = %.3e\n", res_gj);

    //LU 
    /*
    copy_arrays(A_copy, b_copy, A, b, n, m);
    for (int i = 1; i <= n; i++) rhs[i] = b_copy[i][1];

    start = clock();
    ludcmp(A_copy, n, indx, &d);
    lubksb(A_copy, n, indx, rhs);
    end = clock();

    time_lu[t] = 1000.0f * (end - start) / CLOCKS_PER_SEC;
    */
    start = clock();
    for (int r = 0; r < reps; r++) {
        copy_arrays(A_copy, b_copy, A, b, n, m);
        for (int i = 1; i <= n; i++) rhs[i] = b_copy[i][1];
        ludcmp(A_copy, n, indx, &d);
        lubksb(A_copy, n, indx, rhs);
    }
    end = clock();

    time_lu[t] = (1000.0f * (end - start) / CLOCKS_PER_SEC) / reps; 
    printf("\nLU Solution x:\n");
    for (int i = 1; i <= n; i++)
        printf("%8.4f\n", rhs[i]);
    
    //오차 계산 및 출력
    res_lu[t] = residual_norm(A, rhs, b, n, m);
    //printf("[LU] Residual norm = %.3e\n", res_lu);    

    //[2] mprove() 시행 -> lubksb() 본래의 오차는 저장하면서 별개로 mprove 실행 & 저장
    float *b_vec = (float *)malloc((n + 1) * sizeof(float));
    for (int i = 1; i <= n; i++) 
        b_vec[i] = b[i][1];

    for (int iter = 0; iter < 3; iter++) {
        mprove(A, A_copy, n, indx, b_vec, rhs);
        res_mpr[t][iter] = residual_norm(A, rhs, b, n, m);
    }

    free(b_vec);

    //[3] Determinant & Inverse 
    //Det
    float det = d;
    for (int i = 1; i <= n; i++)
        det *= A_copy[i][i];
    printf("\nDeterminant of A%d = %.6e\n", t + 1, det);

    //Inv
    float **inv = (float **)malloc((n + 1) * sizeof(float *));
    for (int i = 1; i <= n; i++)
        inv[i] = (float *)malloc((n + 1) * sizeof(float));

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) rhs[i] = 0.0f;
        rhs[j] = 1.0f;
        lubksb(A_copy, n, indx, rhs);
        for (int i = 1; i <= n; i++)
            inv[i][j] = rhs[i];
    }

    printf("\nInverse of A%d:\n", t + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%10.5f ", inv[i][j]);
        printf("\n");
    }

    for (int i = 1; i <= n; i++)
        free(inv[i]);
    free(inv);

    //위에 svd에서 if (rank == n) 에 대한 else
    } else {
    printf("\n[Gauss-Jordan] singular -> skip\n");
    printf("[LU] singular -> skip\n");
    }

    //동적할당 해제
    for (int i = 1; i <= n; i++) {
        free(A[i]);
        free(b[i]);
        free(A_copy[i]);
        free(b_copy[i]);
        free(v[i]);
    }

    free(A);
    free(b);
    free(A_copy);
    free(b_copy);
    free(indx);
    free(rhs);
    free(w);
    free(v);
    free(xv);
    if (x_gj) free(x_gj);

    }

    printf("\n===================== SUMMARY =====================\n");
    printf("%-12s %-15s %-15s %-15s\n", "System", "SVD", "Gauss-Jordan", "LU");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        printf("lineq%-5d    ", i + 1);
        if (res_svd[i] > 0) printf("%-15.3e", res_svd[i]); else printf("%-15s", "-");
        if (res_gj[i] > 0)  printf("%-15.3e", res_gj[i]);  else printf("%-15s", "-");
        if (res_lu[i] > 0)  printf("%-15.3e", res_lu[i]);  else printf("%-15s", "-");
        printf("\n");
    }

    printf("----------------------------------------------------\n");

    // 평균 계산
    float avg_svd = 0.0f, avg_gj = 0.0f, avg_lu = 0.0f;
    int count_svd = 0, count_gj = 0, count_lu = 0;

    for (int i = 0; i < 3; i++) {
        if (res_svd[i] > 0) { avg_svd += res_svd[i]; count_svd++; }
        if (res_gj[i] > 0)  { avg_gj += res_gj[i];  count_gj++; }
        if (res_lu[i] > 0)  { avg_lu += res_lu[i];  count_lu++; }
    }

    avg_svd = (count_svd > 0) ? avg_svd / count_svd : 0.0f;
    avg_gj  = (count_gj  > 0) ? avg_gj  / count_gj  : 0.0f;
    avg_lu  = (count_lu  > 0) ? avg_lu  / count_lu  : 0.0f;

    printf("Average       %-15.3e %-15.3e %-15.3e\n", avg_svd, avg_gj, avg_lu);
    printf("====================================================\n");

    printf("\n===================== EXECUTION TIME =====================\n");
    printf("%-12s %-15s %-15s %-15s\n", "System", "SVD (ms)", "Gauss-Jordan", "LU");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        printf("lineq%-5d    ", i + 1);
        if (time_svd[i] > 0) printf("%-15.3f", time_svd[i]); else printf("%-15s", "-");
        if (time_gj[i]  > 0) printf("%-15.3f", time_gj[i]);  else printf("%-15s", "-");
        if (time_lu[i]  > 0) printf("%-15.3f", time_lu[i]);  else printf("%-15s", "-");
        printf("\n");
    }

    printf("-----------------------------------------------------------\n");

    float avg_time_svd = 0.0f, avg_time_gj = 0.0f, avg_time_lu = 0.0f;
    count_svd = count_gj = count_lu = 0;

    for (int i = 0; i < 3; i++) {
        if (time_svd[i] > 0) { avg_time_svd += time_svd[i]; count_svd++; }
        if (time_gj[i]  > 0) { avg_time_gj  += time_gj[i];  count_gj++; }
        if (time_lu[i]  > 0) { avg_time_lu  += time_lu[i];  count_lu++; }
    }

    avg_time_svd /= (count_svd > 0 ? count_svd : 1);
    avg_time_gj  /= (count_gj  > 0 ? count_gj  : 1);
    avg_time_lu  /= (count_lu  > 0 ? count_lu  : 1);

    printf("Average       %-15.3f %-15.3f %-15.3f\n",
         avg_time_svd, avg_time_gj, avg_time_lu);
    printf("===========================================================\n");

    printf("\n===================== ITERATIVE IMPROVEMENT =====================\n");
    printf("%-12s %-15s %-15s %-15s %-15s\n", "System", "Iter0(LU)", "Iter1", "Iter2", "Iter3");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        printf("lineq%-5d    ", i + 1);

        // Iter 0: LU 해의 초기 오차
        if (res_lu[i] > 0) printf("%-15.3e", res_lu[i]);
        else printf("%-15s", "-");

        // Iter 1~3: mprove 반복 개선 오차
        for (int j = 0; j < 3; j++) {
            if (res_mpr[i][j] > 0)
                printf("%-15.3e", res_mpr[i][j]);
            else
                printf("%-15s", "-");
        }
        printf("\n");
    }

printf("=================================================================\n");


    return 0;
}
/*
터미널 컴파일 시 명령어:
gcc -o runLinear homework3.c 
NRs/ansi/recipes/gaussj.c 
NRs/ansi/other/nrutil.c 
NRs/ansi/recipes/ludcmp.c 
NRs/ansi/recipes/lubksb.c 
NRs/ansi/recipes/svdcmp.c 
NRs/ansi/recipes/svbksb.c 
NRs/ansi/recipes/pythag.c 
NRs/ansi/recipes/mprove.c 
-I NRs/ansi/other
*/