# 컴파일러와 옵션
CC = gcc
CFLAGS = -Wall -g -I ./NRs/ansi/other

# 실행파일 이름
TARGET = rtbessel.exe

# 소스 파일들
SRCS = homework2.c \
       ./NRs/ansi/recipes/zbrak.c \
       ./NRs/ansi/recipes/rtbis.c \
       ./NRs/ansi/recipes/nrutil.c \
       ./NRs/ansi/recipes/rtflsp.c \
       ./NRs/ansi/recipes/rtsec.c \
       ./NRs/ansi/recipes/rtnewt.c \
       ./NRs/ansi/recipes/rtsafe.c \
       ./NRs/ansi/recipes/bessj0.c \
       ./NRs/ansi/recipes/bessj1.c \
       muller.c

# 오브젝트 파일 (자동 변환)
OBJS = $(SRCS:.c=.o)

# 빌드 규칙
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 일반적인 .c → .o 규칙
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 정리 규칙 (Windows라 del 사용)
.PHONY: clean
clean:
	del $(OBJS) $(TARGET)

# VSCode에서는 윈도우 파워셀을 사용하여 make 가 불가능했다.
# 그래서 MSYS2의 터미널을 사용하여 make를 실행해야 했다.

