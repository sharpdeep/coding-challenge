# -*- coding:utf-8 -*-
#Python 2.7.9
"""
����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������[1,2,4,7,3,5,6,8]�������������[4,7,2,1,5,3,8,6]��
���ؽ������������ء�
"""

class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
		
class Solution:
    # ���ع����TreeNode���ڵ�
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