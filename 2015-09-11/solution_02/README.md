##问题2：

请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则
经过替换之后的字符串为We%20Are%20Happy。

##思路：

用Python解决非常简单 = =，首先将字符串以一个空格为分界符，分为一个List。然后对这
个List内部的空格都替换成'%20'，然后再用join拼接成字符串即可。

##Code

```Python
# -*- coding:utf-8 -*-
class Solution:
        # s 源字符串
        def replaceSpace(self, s):
                # write code here
                words = s.split(' ')
                g = lambda x:'%20' if x == ' 'else x
                return '%20'.join([g(i) for i in words])

if __name__ == '__main__':
        s = Solution()
        print s.replaceSpace('hello world')
```

