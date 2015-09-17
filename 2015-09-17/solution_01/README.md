##问题：
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减序列的一个旋转，输出旋转数组的最小元素，不存在则输出0.例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。

##思路：

**什么是非递减序列**

非递减序列就是对任何两个相邻的元素都有x[i+1] >= x[i],递增序列就是一种特殊的非递减序列，类似｛1，1，1，1｝和｛1，1，1，2，3，3，4｝这些也是非递减序列。

**简单情况**

对于这个问题，首先简单化处理，如果这个序列中没有重复的数，而且是确定旋转了(*因为按照题意，旋转的一个结果就是没有旋转，如{1，2，3，4，5}旋转一次是｛5，1，2，3，4｝，继续旋转下去就可能是｛1，2，3，4，5｝*)。

以｛1，2，3，4，5｝为例，旋转成｛3，4，5，1，2｝，可以看到这个序列分成了两部分，｛3，4，5｝和｛1，2｝，各自都是有序的，且第一个序列中的数都是大于第二个序列中的数的。所以可以仿造二分查找法。

* `index  = (start+end)/2`
* 如果`array[index] > array[start]`，说明`index`是在第一个序列中，令`start = index`(*注意不是二分法的`start=index+1`,因为最终不是想让`start`和`end`指向同一个，而是`start`指向第一个序列的最后一个，`end`指向第二个序列的第一个*)
* 如果`array[index] < array[end]`,说明`index`在第二个序列中，令`end=index`
* 跳出循环的条件是`start<end-1`(*因为`start`指向第一个序列的最后一个，`end`指向第二个序列的第一个*)

**其他情况考虑**

例外情况主要有：

* 序列中有重复元素，如{1，1，0，1，1}，此时`array[start] == array[end]`,此时没办法按第一个方法来，因为无法判断`index`是哪个序列的。所以这种情况下只能用顺序查找。
* 序列没有旋转，如{1，2，3，4，5}，此时用上面的方法是有问题，这时直接返回第一个元素即可。
* 序列没有元素，或者只有一个元素时，因为判断条件是`start<end-1`，所以这些情况可能会导致程序出错，没有元素时返回0即可，只有一个元素时返回该元素。

##Code

```Python
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
```