# -*- coding:utf-8 -*-
"""
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
�����������һ��n����̨���ܹ��ж�����������
"""
class Solution:
    def jumpFloorII(self, number):
        # write code here
        result = 0 # �ڴ�֮ǰ�������ܺ�
        cur = 1
        back = 1
        while(number):
            cur = back
            result += cur
            back = result + 1
            number -= 1
        return cur

if __name__ == '__main__':
    s = Solution()
    print s.jumpFloorII(10)