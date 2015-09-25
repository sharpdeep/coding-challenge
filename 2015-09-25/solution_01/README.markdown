# 调整数组顺序使奇数位于偶数前面

##问题：
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

##思路：

- Python列表解析：
  利用Python的列表解析，按顺序提取所有奇数和偶数，再将两个列表合并
- 一般思路：
  类似冒泡排序法，两两前后比较，如果前偶后奇则交换，执行(n-1)趟即可。

##Code

- Python列表解析法：
```Python
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
```
- 一般法：
```C
#include<stdio.h>
	
void reOrderArray(vector<int> &array) {
	int i,j,temp;
    int len = array.size();
    for(i = 0; i < len - 1; i++){
        for(j = len - 1; j > i; j--){
            if(array[j]%2==1 && array[j-1]%2==0){
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
}

void main()
{
	int array[10] = {4,2,1,2,5,6,7,8,5,10};
	int i;
	reOrderArray(array);
	for(i = 0; i < 10; i++){
		print("%d",array[i]);
	}
}
```




