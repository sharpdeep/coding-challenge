#include<stdio.h>

int numberOf1(int n)
{
	int count = 0;
	while(n){
		n = n & (n-1);
		count++;
	}
	return count;
}

void main()
{
	int count = numberOf1(-5);
	printf("%d",count);
}
