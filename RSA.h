#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Binary
{
	int num;
	char* bin;
} Binary;

int isPrime(unsigned long long);
unsigned long long power(int, int);
unsigned long long gcd(unsigned long long, long long);
unsigned long long inverse(int, unsigned long long);
unsigned long long SquandMulti(long long, unsigned long long, unsigned long long);
Binary* binaryConvert(unsigned long long);