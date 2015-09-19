# -*- coding:utf-8 -*-
"""
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
"""
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