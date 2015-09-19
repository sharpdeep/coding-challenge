# -*- coding:utf-8 -*-
"""
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
"""
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