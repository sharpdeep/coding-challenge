# -*- coding:utf-8 -*-
"""
һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
�����������һ��n����̨���ܹ��ж�����������
"""
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
	s.jumpFloor(10)