#include <stdio.h>

int main(void) {
    char a; short b; int c; long d;
    a = 1;
    b = 2;
    c = 3;
    d = 4;

    return 0;
}

/*
   0x00007ff766a61450 <+0>:     push   %rbp
   0x00007ff766a61451 <+1>:     mov    %rsp,%rbp
   0x00007ff766a61454 <+4>:     sub    $0x30,%rsp
   0x00007ff766a61458 <+8>:     call   0x7ff766a61550 <__main>
   0x00007ff766a6145d <+13>:    movb   $0x1,-0x1(%rbp)
   0x00007ff766a61461 <+17>:    movw   $0x2,-0x4(%rbp)
   0x00007ff766a61467 <+23>:    movl   $0x3,-0x8(%rbp)
   0x00007ff766a6146e <+30>:    movl   $0x4,-0xc(%rbp)
   0x00007ff766a61475 <+37>:    mov    $0x0,%eax
   0x00007ff766a6147a <+42>:    add    $0x30,%rsp
   0x00007ff766a6147e <+46>:    pop    %rbp
   0x00007ff766a6147f <+47>:    ret
*/
