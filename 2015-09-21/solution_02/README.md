#数值的整数次方

##问题：
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

##思路：
这里可以用递归也可以用非递归。这个问题需要注意的是以下几点：

* 当`exponent==0`时，返回1;
* 当`exponent < 0`时，将`-exponent`递归调用，返回结果为`1/Power(base,-exponent)`;
* 当`exponent > 0`时，可以递归或者动态规划求解;
* 当`base == 0 && exponent < 0`时，可能会出现分母为0的情况，应单独返回。

##Code

* 递归法：
```C
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

```

* 动态规划法
```C
#include<stdio.h>

double Power(double base, int exponent)
{
        double cur = 1;
        double back = base;
        if(base == 0){
                return 0;
        }
        if(exponent < 0){
                return 1/Power(base,-exponent);
        }
        while(exponent--){
                cur = back;
                back = cur*base;
        }
        return cur;
}

void main()
{
	double result = Power(3.0,5);
	printf("%f",result);
}
```
