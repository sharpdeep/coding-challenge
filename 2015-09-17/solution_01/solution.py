# -*- coding:utf-8 -*-
"""
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减序列的一个旋转，输出旋转数组的最小元素，不存在则输出0。例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
"""
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        start = 0
        end = len(rotateArray) - 1
        if(len(rotateArray) == 0): #输入为空
            return 0
        if(len(rotateArray) == 1): #一个输入
            return rotateArray[0]
        if(rotateArray[0] < rotateArray[-1]): #没有旋转
        	return rotateArray[0]
        while(start < end - 1):
            if(rotateArray[start] == rotateArray[end]): #有重复
                return self.findMin(start,end,rotateArray)
            index = (start+end)/2
            if(rotateArray[index] > rotateArray[start]):
                start = index	
            elif(rotateArray[index] < rotateArray[end]):
                end = index
      	return rotateArray[end]
 	
    def findMin(self,start,end,array):
    	min = array[start]
        start += 1
        while(start <= end):
            if(array[start] < min):
                min = array[start]
            start += 1
        return min
		
if __name__ == '__main__':
	s = Solution()
	result = s.minNumberInRotateArray([2,2,1,2,2,2])
	print result