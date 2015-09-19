##问题：
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

##思路：
青蛙想要跳上第n阶，必然是从第n-1级跳上来的或者是从第n-2级跳上来的，所以有F(n)=F(n-1)+F(n-2),其实就是一个斐波那契数列。边界条件是：

* 当`n=1`时，`F(n) = 1`;
* 当`n=2`时，`F(n) = 2`; 

##Code:
这里可以用递归来解决问题，如下：

```Python
# -*- coding:utf-8 -*-
class Solution:
    def jumpFloor(self, number):
        # write code here
        if number == 1:
            return 1
        if number == 2:
            return 2
        return self.jumpFloor(number-1)+self.jumpFloor(number-2)
if __name__ == '__main__':
	s = Solution()
	print s.jumpFloor(10)
```

但是当值比较大时，递归就会出现性能问题了，比如运行时间太长。因此采用动态规划来解决问题。
 
```Python
# -*- coding:utf-8 -*-
class Solution:
    def jumpFloor(self, number):
        # write code here
        cur = 1
        back = 1
        while(number > 0):
            back += cur
            cur = back - cur
            number -= 1
        return cur
if __name__ == '__main__':
	s = Solution();
	print s.jumpFloor(10)
```
 
 