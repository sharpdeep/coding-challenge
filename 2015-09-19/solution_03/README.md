##���⣺
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����

##˼·��
С���ο��Ժ��ŷ�Ҳ�������ŷš������n�������ŷţ���ǰ��`2*(n-1)`�Ѿ�����������ǵ�n���Ǻ��ŷţ���ǰ��`2*��n-2��`�Ѿ�������������`F(n) = F(n-1)+F(n-2)`������һ��쳲������������⡣

##Code:
```Python
# -*- coding:utf-8 -*-
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
```