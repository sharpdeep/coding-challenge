##问题：
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。

##思路：
一开始看到斐波那契数列想到的就是递归的方法，于是写下如下代码：

```Python
# -*- coding:utf-8 -*-
class Solution:
    def Fibonacci(self, n):
        # write code here
        if(n == 0):
            return 0
        if(n == 1 or n == 2):
            return 1
        return self.Fibonacci(n-1)+self.Fibonacci(n-2)
		
if __name__ == '__main__':
	s = Solution()
	s.Fibonacci(400)
```

然后程序就一直跑着没有停下来，**用递归时间太长了**，于是改进了一下，采用动态规划的办法。即是用两个变量指向最新的两个数(初始为0和1)，然后不断更新这两个变量，保证每次第一个变量就是要返回的值

##Code

```Python
class Solution:
    def Fibonacci(self, n):
        # write code here
        first = 0
        second = 1
        while(n > 0):
            second += first
            first = second - first
            n -= 1
        return first
		
if __name__ == '__main__':
	s = Solution()
	result = s.Fibonacci(400)
	print result
```