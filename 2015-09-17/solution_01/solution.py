# -*- coding:utf-8 -*-
"""
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת������һ���ǵݼ����е�һ����ת�������ת�������СԪ�أ������������0����������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
"""
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        start = 0
        end = len(rotateArray) - 1
        if(len(rotateArray) == 0): #����Ϊ��
            return 0
        if(len(rotateArray) == 1): #һ������
            return rotateArray[0]
        if(rotateArray[0] < rotateArray[-1]): #û����ת
        	return rotateArray[0]
        while(start < end - 1):
            if(rotateArray[start] == rotateArray[end]): #���ظ�
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