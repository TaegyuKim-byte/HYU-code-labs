# ============ 설정 영역 ============
CC = gcc
CFLAGS = -I NRs/ansi/other       # 헤더 파일 경로
TARGET = runLinear               # 실행 파일 이름
SRC = homework3.c \
      NRs/ansi/recipes/gaussj.c \
      NRs/ansi/other/nrutil.c \
      NRs/ansi/recipes/ludcmp.c \
      NRs/ansi/recipes/lubksb.c \
      NRs/ansi/recipes/svdcmp.c \
      NRs/ansi/recipes/svbksb.c \
      NRs/ansi/recipes/pythag.c \
      NRs/ansi/recipes/mprove.c

# ============ 빌드 규칙 ============
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS)

# ============ 기타 유틸리티 ============
# 실행 파일과 객체 파일 제거
clean:
	rm -f $(TARGET) *.o

# 재컴파일 (clean + all)
rebuild: clean all

