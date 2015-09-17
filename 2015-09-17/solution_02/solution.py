# -*- coding:utf-8 -*-
"""
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
"""
class Solution:
    def Fibonacci(self, n):
        # write code here
        first = 0
        second = 1
        while(n > 0):
            second += first
            first = second - first
            n -= 1
        return first
		
if __name__ == '__main__':
	s = Solution()
	result = s.Fibonacci(400)
	print result