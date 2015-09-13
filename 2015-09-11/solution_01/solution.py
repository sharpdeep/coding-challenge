#coding=utf-8
#Python 2.7.9
"""
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完
成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
"""

class Solution(object):
    def Find(self,array,target):
        row = 0
        col = len(array[0])-1
        while(row < len(array) and col >= 0):
            if(target == array[row][col]):
                return True
            elif(target > array[row][col]):
                row += 1
            elif(target < array[row][col]):
                col -= 1 
        return False       

if __name__ == '__main__':
    s = Solution()
    print s.Find([[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]],7)
