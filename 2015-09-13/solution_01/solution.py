# -*- coding:utf-8 -*-
#Python 2.7.9
"""
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列[1,2,4,7,3,5,6,8]和中序遍历序列[4,7,2,1,5,3,8,6]，
则重建二叉树并返回。
"""

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