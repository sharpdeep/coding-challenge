# -*- coding:utf-8 -*-
"""
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
"""
class Solution:
	def reOrderArray(self, array):
        	# write code here
	        result = [i for i in array if i%2==1]
		result.extend([i for i in array if i%2==0])
		return result

if __name__ == '__main__':
	s = Solution()
	print s.reOrderArray([2,3,1,5,4,7,4,3,9])
