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
	);

	return 0;
}

