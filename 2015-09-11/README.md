##问题 1：

在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

##思路：

首先，从描述中可以得到以下信息：

- 某个位置的数，同一行的左边一定都比他小，同一列的下边一定都比他大

- 如果一行的最后一个数 < target, 那target绝对不会在这一行

- 某个位置的数，其左上方区域肯定都比他小，其右下方的区域肯定都比他大，可用反证法证明


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

---

##问题2：

请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

##思路：

用Python解决非常简单 = =，首先将字符串以一个空格为分界符，分为一个List。然后对这个List内部的空格都替换成'%20'，然后再用join拼接成字符串即可。

##Code

```Python
# -*- coding:utf-8 -*-
class Solution:
	# s 源字符串
        def replaceSpace(self, s):
		# write code here
		words = s.split(' ')
		g = lambda x:'%20' if x == ' 'else x
		return '%20'.join([g(i) for i in words])

if __name__ == '__main__':
	s = Solution()
	print s.replaceSpace('hello world')
```

---

##问题3：
输入一个链表，从尾到头打印链表每个节点的值。

##思路：
第一反应就是利用堆来实现，但是Python用List就是解决一切。遍历链表并append进List中，然后用List的切片(`[::-1]`)特性倒序返回

##Code:

```Python
# -*- coding:utf-8 -*-
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

listNode = ListNode(1)

listNode2 = ListNode(2)
listNode.next = listNode2

listNode3 = ListNode(3)
listNode2.next = listNode3

listNode4 = ListNode(4)
listNode3.next = listNode4


class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        buffer = []
        while not listNode == None:
            buffer.append(listNode.val)
            listNode = listNode.next
        return buffer[::-1]
		
if __name__ == '__main__':
	s = Solution()
	result = s.printListFromTailToHead(listNode)
	print result
```