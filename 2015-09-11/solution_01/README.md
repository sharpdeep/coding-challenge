##问题 1：

在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的
顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该
整数。

##思路：

首先，从描述中可以得到以下信息：

- 某个位置的数，同一行的左边一定都比他小，同一列的下边一定都比他大

- 如果一行的最后一个数 < target, 那target绝对不会在这一行

- 某个位置的数，其左上方区域肯定都比他小，其右下方的区域肯定都比他大，可用反证法
证明


因此可以从右上角开始比较，

如果 == target,则找到;

如果 < target, 排除这一行，target一定就在左下方区域或者不存在,下移一行;

如果 > target，则有可能在这一行的左边或者左下方区域或者不存在，左移一列;

##Code:
```Python
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

```
