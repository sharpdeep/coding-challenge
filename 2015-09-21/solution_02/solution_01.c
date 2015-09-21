/*
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 */
#include<stdio.h>

double Power(double base, int exponent)
{
	if(base == 0){
		return 0;
	}
	if(exponent == 0){
		return 1;
	}else if(exponent < 0){
		return 1/(Power(base,-exponent));
	}else{
		return base * Power(base,exponent-1);
	}
}

void main()
{
	double result = Power(3.0,5);
	printf("%f",result);
}
