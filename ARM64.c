// ARM64.c 
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned A, B, Q, Z, N;	

int main()
{
	printf("Size of unsigned %d\n", sizeof(unsigned));
	printf("Size of int %d\n", sizeof(int));
	printf("Size of uchar %d\n", sizeof(unsigned char));
	printf("Input dividend: ");
	scanf("%u", &A);
	printf("Input divider: ");
	scanf("%u", &B);
	printf("A= %u, B= %u\n", A, B);

    asm(
        "adr x4, A\n"
        "ldr x0, [x4]\n"
        "adr x4, B\n"
        "ldr x1, [x4]\n"
        "mov x4, #16\n"      //
        "mov x2, #0\n"      // get N elder bits of A
        "asr x2, x0, x4\n" //
        "mov x3, #0\n"
        "sub x3, x2, x1\n"
        "cmp x3, #0\n"
        "bge more\n"
        "bl less\n"
        "more:\n"
        "mov x8, #0\n"
        "less:\n"
    );

	return 0;
}

