# -*- coding:utf-8 -*-
"""
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
"""
class Solution:
    def rectCover(self, number):
        # write code here
        pre = 0
        cur = 1
        while(number):
            cur += pre
            pre = cur - pre
            number -= 1
        return cur

if __name__  == '__main__':
    s = Solution()
    print s.rectCover(10)