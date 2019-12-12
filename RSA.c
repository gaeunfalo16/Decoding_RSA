#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "RSA.h"

int isPrime(unsigned long long num)
{
	if (num <= 1)
	{
		return 0;
	}

	if (num % 2 == 0)
	{
		return num == 2 ? 0 : 1;
	}

	for (int i = 3; i <= sqrt(num); i += 2)
	{
		if (num % i == 0)
		{
			return 0;
		}
	}

	return 1;
}


unsigned long long power(int bot, int index) 
{
	if (index == 0)
	{
		return 1;
	}

	return power(bot, index - 1) * bot;
}

unsigned long long gcd(unsigned long long a, long long b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}

unsigned long long inverse(int a, unsigned long long b)
{
	long long r1, r2, q, r, t, t1, t2;
	r1 = a;
	r2 = b;
	t1 = 0; t2 = 1;

	while (r1 != 1)
	{
		q = r2 / r1;
		r = r2 - r1 * q;
		t = t1 - t2 * q;
		r2 = r1;
		r1 = r;
		t1 = t2;
		t2 = t;
	}

	if (t2 < 0)
	{
		t2 = t2 + b;
	}

	return t2;
}

unsigned long long SquandMulti(long long bottom, unsigned long long e, unsigned long long n)
{
	Binary* Bin = (Binary*)malloc(sizeof(Binary));

	if (Bin == NULL)
	{
		printf("Error occurs\n");
		return -1;
	}
	
	Bin = binaryConvert(e);

	unsigned long long fin = 1;
	int i;

	for (i = Bin->num; i >= 0; i--)
	{
		fin = power(fin, 2) % n;
		if (i == 1)
		{
			fin = (fin * bottom) % n;
		}

		return fin;
	}
}

Binary* binaryConvert(unsigned long long num)
{
	Binary* myBin = (Binary*)malloc(sizeof(Binary));
	
	if (myBin == NULL)
	{
		printf("Error occurs\n");
		return -1;
	}

	myBin->bin = (char*)malloc(sizeof(char));
	myBin->num = 0;
	
	int i = 0;

	while (num > 0)
	{
		if (num % 2 == 1)
		{
			myBin->bin[i] = 1;
		}
		else
		{
			myBin->bin[i] = 0;
		}
		i++;
		num = num / 2;

	}

	myBin->num = i;

	return myBin;
}