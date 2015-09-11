# -*- coding:utf-8 -*-
class Solution:
	# s Ô´×Ö·û´®
        def replaceSpace(self, s):
		# write code here
		words = s.split(' ')
		g = lambda x:'%20' if x == ' 'else x
		return '%20'.join([g(i) for i in words])

if __name__ == '__main__':
	s = Solution()
	print s.replaceSpace('hello world')
