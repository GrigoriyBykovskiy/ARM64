// ARM64.c 
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned A, B, Q = 0, Z, N;

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
    "mov x5, #0\n" // x5 = Q;
    "adr x4, A\n"
    "ldr x0, [x4]\n" // x0 = A;
    "adr x4, B\n"
    "ldr x1, [x4]\n" // x1 = B;
	"cmp x1, #0\n"
	"beq stop\n" // if (B == 0) exit;
	"adr x4, N\n"
	"ldr x2,[x4]\n" // x2 = N
    "lsr x3, x0, x2\n" // x3 = Z (N elder bits of A)
	"mov x4, #0\n"
    "sub x4, x3, x1\n" // x4 = Z - B
	"cmp x4, #0\n" // if (Z > 0) exit;
    "bgt stop\n"
    "mov x4, #0\n"// x4 = i;
	"loop:\n"
	"cmp x4, x2\n" // if i == N exit;
	"beq stop\n"
	"lsl x3, x3, #1\n" // z << 1
    "mov x12, #1\n"
    "mov x13, #0\n"
    "mov x14, #0\n"
    "mov x15, #0\n"
    "sub x15, x2, x4\n"// buf = N - I
    "lsl x13, x12, x15\n" // x13 = x12 << buf
    "and x14, x0, x13\n" // x14 = x0 & x 13
    "lsr x14, x14, x15\n" // x14 = x14 >> buf
    "add x3, x3, x14\n"// z(0) = A (N - I)
    "mov x6, #0\n"
    "sub x6, x3, x1\n"// x6 = Z - B
    "cmp x6, #0\n"// if (Z > 0)
    "bgt addone\n"
    "add x4, x4, #1\n" //i++
    "b loop\n"
    "addone:\n"
    "mov x7, #1\n"      //
    "lsl x7, x7, x15\n"// Q(N - I) = 1;
    "add x5, x5, x7\n"//
    "add x4, x4, #1\n"  // i++
	"b loop\n"
	"stop:\n"
    "adr x4, Q\n"
    "str x5, [x4]\n"
    );
    printf("Q is %d\n", Q);
    printf("Z is %d\n", Z);
	return 0;
}

