##问题：
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法

##思路：
很类似上一题的[跳台阶](../solution_01), 但是这里如果用递归就很勉强了，试想一下：`F(n) = F(n-1)+F(n-2)+F(n-3)+...+F(1)+F(0)`。所以这里不好再用递归，用动态规划。  
先尝试找规律。
> F(n) = F(n-1)+F(n-2)+...F(1)+F(0)

可以看出，第n级的次数=前面n-1次的总和+1(`F(0)`)

可以看一下具体的例子：
> F(1) = 1
> F(2) = 2
> F(3) = 4
> F(4) = 8

因此可以用一个变量存储前面的累积和，然后通过这个累计和计算下一个值。

##Code：
```Python
# -*- coding:utf-8 -*-
class Solution:
    def jumpFloorII(self, number):
        # write code here
        result = 0 # 在此之前的数的总和
        cur = 1
        back = 1
        while(number):
            cur = back
            result += cur
            back = result + 1
            number -= 1
        return cur

if __name__ == '__main__':
    s = Solution()
    print s.jumpFloorII(10)
```
