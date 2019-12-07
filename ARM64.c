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
	N = 16; // len of register

    asm(
	"start:\n"
        "adr x4, A\n"      //
        "ldr x0, [x4]\n"  // x0 = A;
        "adr x4, B\n"    //
        "ldr x1, [x4]\n"// x1 = B;
	"cmp x1, #0\n" // if (B == 0)
	"beq stop\n"  //		exit;
	"adr x4, N\n"	//
	"ldr x2,[x4]\n"// x2 = N
        "lsr x3, x0, x2\n" // x3 = Z (N elder bits of A)
	"mov x4, #0\n"
        "sub x4, x3, x1\n"// x4 = Z - B
	"cmp x4, #0\n"// if (Z > 0) exit;
        "bgt stop\n"
        "mov x4, #0\n"// x4 = i;
	"loop:\n"
	"cmp x4, x2\n"
	"beq stop\n"
	"add x4, x4, #1\n"
	"lsl x3, x3, #1\n" // z << 1
	"\n"
	"b loop\n"
	"stop:\n"
    );

	return 0;
}

