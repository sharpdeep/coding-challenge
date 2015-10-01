#coding-challenge

##2015-10-01

####[从上到下打印二叉树](2015-10-01/solution_01)
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

####[二叉搜索树的后序遍历序列](2015-10-01/solution_02)
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

####[二叉树中和为某一值的路径](2015-10-01/solution_03)
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

####[复杂链表的复制](2015-10-01/solution_04)
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）。


##2015-09-30

####[反转链表](2015-09-30/solution_01)
输入一个链表，反转链表后，输出链表的所有元素。

####[合并两个排序的链表](2015-09-30/solution_02)
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

####[树的子结构](2015-09-30/solution_03)
输入两颗二叉树A，B，判断B是不是A的子结构。

####[二叉树的镜像](2015-09-30/solution_04)
操作给定的二叉树，将其变换为源二叉树的镜像。

####[顺时针打印矩阵](2015-09-30/solution_05)
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵： 
```
1  2  3  4 
5  6  7  8 
9 10 11 12 
13 14 15 16
```
则依次打印出数字
```
1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
```

####[包含min函数的栈](2015-09-30/solution_06)
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

####[栈的压入，弹出序列](2015-09-30/solution_07)
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列`1,2,3,4,5`是某栈的压入顺序，序列`4,5,3,2,1`是该压栈序列对应的一个弹出序列，但`4,3,5,1,2`就不可能是该压栈序列的弹出序列。


##2015-09-25

####[调整数组顺序使奇数位于偶数前面](2015-09-25/solution_01)
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

####[链表中倒数第k个结点](2015-09-25/solution_02)
输入一个链表，输出该链表中倒数第k个结点。


##2015-09-21

####[二进制中1的个数](2015-09-21/solution_01)
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

####[数值的整数次方](2015-09-21/solution_02)
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

##2015-09-19

####[跳台阶](2015-09-19/solution_01)
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

####[变态跳台阶](2015-09-19/solution_02)
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法

####[矩形覆盖](2015-09-19/solution_03)
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

##2015-09-17

####[旋转数组的最小数字](2015-09-17/solution_01)
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减序列的一个旋转，输出旋转数组的最小元素，不存在则返回0.例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。

####[斐波那契数列](2015-09-17/solution_02)
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。


##2015-09-11

####[二叉树重建](2015-09-13/solution_01)
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列[1,2,4,7,3,5,6,8]和中序遍历序列[4,7,2,1,5,3,8,6]，则重建二叉树并返回。

####[用两个栈实现队列](2015-09-13/solution_02)
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。


##2015-09-11    

####[二维有序数组查找](./2015-09-11/solution_01)    
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完
成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

####[替换空格](./2015-09-11/solution_02)
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

####[从尾到头打印链表](./2015-09-11/solution_03)
输入一个链表，从尾到头打印链表每个节点的值。




