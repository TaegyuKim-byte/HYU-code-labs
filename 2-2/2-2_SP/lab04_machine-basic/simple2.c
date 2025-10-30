#include <stdio.h>

struct name {
    char first[12];
    char last[12];
};

long main() {
    long i = 3; long *pi = &i;
    long arr[10]; struct name n;

    *pi = 1;
    arr[0] = 0x30;
    arr[1] = 0x31;
    n.first[0] = 0x32;
    n.first[1] = 0x33;
    return 0;
}

/*
   0x0000000140001450 <+0>:     push   %rbp
   0x0000000140001451 <+1>:     mov    %rsp,%rbp
   0x0000000140001454 <+4>:     add    $0xffffffffffffff80,%rsp
   0x0000000140001458 <+8>:     call   0x140001570 <__main>
   0x000000014000145d <+13>:    movl   $0x3,-0xc(%rbp)
   0x0000000140001464 <+20>:    lea    -0xc(%rbp),%rax
   0x0000000140001468 <+24>:    mov    %rax,-0x8(%rbp)
   0x000000014000146c <+28>:    mov    -0x8(%rbp),%rax
   0x0000000140001470 <+32>:    movl   $0x1,(%rax)
   0x0000000140001476 <+38>:    movl   $0x30,-0x40(%rbp)
   0x000000014000147d <+45>:    movl   $0x31,-0x3c(%rbp)
   0x0000000140001484 <+52>:    movb   $0x32,-0x60(%rbp)
   0x0000000140001488 <+56>:    movb   $0x33,-0x5f(%rbp)
   0x000000014000148c <+60>:    mov    $0x0,%eax
   0x0000000140001491 <+65>:    sub    $0xffffffffffffff80,%rsp
   0x0000000140001495 <+69>:    pop    %rbp
   0x0000000140001496 <+70>:    ret
*/