// ARM64.c : Defines the entry point for the console application.
//

#include <stdio.h>
int q;
int a = 2, b = 3;
int c = 4;

int main()
{
	printf("test asm\n");
	printf("a= %d, b= %d, c= %d\n", a, b, c);
	asm(
		"adr x4, a\n"
		"ldr x0, [x4]\n"
		"adr x4, b\n"
		"ldr x1, [x4]\n"
		"add x3, x0, x1\n"
		"adr x4, c\n"
		"ldr x2, [x4]\n"
		"sub x3, x3, x2\n"
		"adr x4, q\n"
		"str x3, [x4]"
	);
	printf("q= %d\n", q);
	return 0;
}
