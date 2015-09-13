##问题：

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列[1,2,4,7,3,5,6,8]和中序遍历序列[4,7,2,1,5,3,8,6]，则重建二叉树并返回。

##思路：

想到树就一定会想到递归，反思之前手工还原二叉树的流程，得到如下步骤：

* 从前序遍历中提取第一个元素，这就是根节点；
* 然后在中序遍历中找到根节点的位置，将其分为两部分，左子树和右子树；
* 然后根据左子树和右子树，再将前序遍历划分左右子树，得到各自的前序遍历，递归调用第一步...


##Code:
```Python
#coding=utf-8
#Python 2.7.9

class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
		
class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        # write code here
        if(len(pre) == 0 or len(tin) == 0):
            return None
        node = TreeNode(pre[0])
        index = tin.index(pre[0])
        node.left = self.reConstructBinaryTree(pre[1:len(tin[:index])+1],tin[:index])
        node.right = self.reConstructBinaryTree(pre[len(tin[:index])+1:],tin[index+1:])
        return node

if __name__ == '__main__':
	pre = [1,2,4,7,3,5,6,8]
	tin = [4,7,2,1,5,3,8,6]
	s = Solution()
	s.reConstructBinaryTree(pre,tin)

```
