##问题3：
输入一个链表，从尾到头打印链表每个节点的值。

##思路：
第一反应就是利用堆来实现，但是Python用List就是解决一切。遍历链表并append进List中
，然后用List的切片(`[::-1]`)特性倒序返回

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

