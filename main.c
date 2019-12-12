#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "RSA.h"

int c1 = 125;
int c2 = 625;
int c3 = 165; // c1^2 * c2 * c3 = c
int e = 13;
int c = 1220703125;
unsigned long long n = 9943237852845877651; // scope okay

int main(void)
{
	unsigned long long on; // @(n)
	unsigned long long d;
	unsigned long long msg;

	for (on = power(10, 18) * 9; on < n; on++) // i = @(n)
	{
		if (gcd(on, e) == 1) // @(n) and i have gcd 1.
		{
			d = inverse(e, on); // Find d which is inverse of e on @(n)
			msg = SquandMulti(c, d, n); // Solving C to find mesasge
			printf("The message is : %llu\n", msg);
		}
	}

	printf("Check Finish\n");

	return 0;
}

