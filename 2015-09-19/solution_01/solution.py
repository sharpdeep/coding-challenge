# -*- coding:utf-8 -*-
"""
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
"""
class Solution:
    def jumpFloor(self, number):
        # write code here
        cur = 1
        back = 1
        while(number > 0):
            back += cur
            cur = back - cur
            number -= 1
        return cur
if __name__ == '__main__':
	s = Solution();
	s.jumpFloor(10)