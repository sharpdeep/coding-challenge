##���⣺
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�

##˼·��
һ��ʼ����쳲����������뵽�ľ��ǵݹ�ķ���������д�����´��룺

```Python
# -*- coding:utf-8 -*-
class Solution:
    def Fibonacci(self, n):
        # write code here
        if(n == 0):
            return 0
        if(n == 1 or n == 2):
            return 1
        return self.Fibonacci(n-1)+self.Fibonacci(n-2)
		
if __name__ == '__main__':
	s = Solution()
	s.Fibonacci(400)
```

Ȼ������һֱ����û��ͣ������**�õݹ�ʱ��̫����**�����ǸĽ���һ�£����ö�̬�滮�İ취����������������ָ�����µ�������(��ʼΪ0��1)��Ȼ�󲻶ϸ�����������������֤ÿ�ε�һ����������Ҫ���ص�ֵ

##Code

```Python
class Solution:
    def Fibonacci(self, n):
        # write code here
        first = 0
        second = 1
        while(n > 0):
            second += first
            first = second - first
            n -= 1
        return first
		
if __name__ == '__main__':
	s = Solution()
	result = s.Fibonacci(400)
	print result
```