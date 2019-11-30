// ARM64.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned A, B, Q, Z, N;	

int main()
{
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

