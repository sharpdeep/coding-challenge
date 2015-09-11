#coding=utf-8
#Python 2.7.9

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
