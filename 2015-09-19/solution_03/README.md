##问题：
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

##思路：
小矩形可以横着放也可以竖着放。如果第n个是竖着放，则前面`2*(n-1)`已经放满；如果是第n个是横着放，则前面`2*（n-2）`已经放满。所以有`F(n) = F(n-1)+F(n-2)`，还是一个斐波那契数列问题。

##Code:
```Python
# -*- coding:utf-8 -*-
class Solution:
    def rectCover(self, number):
        # write code here
        pre = 0
        cur = 1
        while(number):
            cur += pre
            pre = cur - pre
            number -= 1
        return cur

if __name__  == '__main__':
    s = Solution()
    print s.rectCover(10)
```