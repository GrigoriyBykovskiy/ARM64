// ARM64.c : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
#define REGISTER_LENGTH 32
#include <stdio.h>

unsigned A, B, C, Q;
int Z;

void get_bits(unsigned number) //little-endian format
{
	int array_of_bits[32];
	printf("%d : ", number);
	for (int i = 0; i < 32; i++) {
		if ((number & (1 << i)) == 0) {
			array_of_bits[i] = 0;
		}
		else {
			array_of_bits[i] = 1;
		}
		printf("%d", array_of_bits[i]);
	}
	printf("\n");
};

unsigned set_elder_bits(unsigned get_number) //little-endian format
{
	int array_of_bits[32];
	unsigned set_number = 0;
	for (int i = 0; i < 32; i++) {
		if ((get_number & (1 << i)) == 0)
			array_of_bits[i] = 0;
		else 
			array_of_bits[i] = 1;
	}
	for (int i = 0; i < 16; i++)
	{
		if (array_of_bits[i] == 1)
			set_number |= (1 << i);
		else
			set_number &= ~(1 << i);
	}
	return set_number;
};

int main()
{
	//printf("Size of unsigned is %d byte\n", sizeof(int));
	printf("Input dividend:\n");
	scanf("%u",&A);
	printf("Input divisor:\n");
	scanf("%u", &B);
	printf("A = %u, B = %u \n", A, B);
	Z = set_elder_bits(A);
	printf("%d\n", Z);
	Z -= B;
	printf("%d\n", Z);

	if ((Z > 0) || (B == 0)) 
	{
		printf("Error!\n");
		return 0;
	}
	else
	{
		Z += B;
		for (int i = 0; i < REGISTER_LENGTH; i++)
		{
			Z << 1;
			Z -= B;
			// Z(0) = A (N-1)

			if (Z > 0) 
			{
				/*some code*/
			}
			else
			{
				/*some code*/
			}
		}
	}
		

	return 0;
}
