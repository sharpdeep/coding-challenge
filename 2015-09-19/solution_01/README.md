##���⣺
һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������

##˼·��
������Ҫ���ϵ�n�ף���Ȼ�Ǵӵ�n-1���������Ļ����Ǵӵ�n-2���������ģ�������F(n)=F(n-1)+F(n-2),��ʵ����һ��쳲��������С��߽������ǣ�

* ��`n=1`ʱ��`F(n) = 1`;
* ��`n=2`ʱ��`F(n) = 2`; 

##Code:
��������õݹ���������⣬���£�

```Python
# -*- coding:utf-8 -*-
class Solution:
    def jumpFloor(self, number):
        # write code here
        if number == 1:
            return 1
        if number == 2:
            return 2
        return self.jumpFloor(number-1)+self.jumpFloor(number-2)
if __name__ == '__main__':
	s = Solution()
	print s.jumpFloor(10)
```

���ǵ�ֵ�Ƚϴ�ʱ���ݹ�ͻ�������������ˣ���������ʱ��̫������˲��ö�̬�滮��������⡣
 
```Python
# -*- coding:utf-8 -*-
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
	print s.jumpFloor(10)
```
 
 