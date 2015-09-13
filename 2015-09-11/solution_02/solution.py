# -*- coding:utf-8 -*-
# python2.7.9
"""
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
"""

class Solution:
	# s 源字符串
        def replaceSpace(self, s):
		# write code here
		words = s.split(' ')
		g = lambda x:'%20' if x == ' 'else x
		return '%20'.join([g(i) for i in words])

if __name__ == '__main__':
	s = Solution()
	print s.replaceSpace('hello world')
