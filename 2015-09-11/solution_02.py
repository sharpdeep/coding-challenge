# -*- coding:utf-8 -*-
# python2.7.9
"""
��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
"""

class Solution:
	# s Դ�ַ���
        def replaceSpace(self, s):
		# write code here
		words = s.split(' ')
		g = lambda x:'%20' if x == ' 'else x
		return '%20'.join([g(i) for i in words])

if __name__ == '__main__':
	s = Solution()
	print s.replaceSpace('hello world')
