# -*- coding:utf-8 -*-
"""
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
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
