# -*- coding:utf-8 -*-
"""
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�
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