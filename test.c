// test.c
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned Q = 0;

int main()
{
    asm(
    "start:\n"
    "mov x5, #5"
    "adr x4, Q\n"
    "str x5, [x4]\n"
    );
    printf("Q is %d\n", Q);
    return 0;
}
