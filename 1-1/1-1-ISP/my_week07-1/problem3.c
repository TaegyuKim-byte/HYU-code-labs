#include <stdio.h>

int main()
{
    //char short int long 1 2 4 8
    //float double 4 8 
    long principal, period;
    int i, interest;
    long total;
    
    printf("principal and period: ");
    scanf("%ld %ld", &principal, &period);
    interest = 10; // 단위 : %임 
    
    interest = principal / 100 * interest; 
    // 원금에 매 기간마다 더해질 이자 값 
    for (i=0, total = principal; i<period; i++) {
        total += interest;
    }
    
    printf("Total: %ld\n", total);
    
    return 0;
}
