﻿#反转链表

##问题：
输入一个链表，反转链表后，输出链表的所有元素。

##思路：
对链表进行遍历的同时，新建一个链表，采用前插法插入数据。

##Code
```C++
#include<iostream>
#include<stdlib.h>

using namespace std;

struct ListNode{
        int val;
        struct ListNode *next;
        ListNode(int x):
                val(x),next(NULL){

                }
};

class Solution {
public:
        ListNode* ReverList(ListNode* pListHead){
                ListNode* node = NULL;
                ListNode* q = NULL;

                while(pListHead){
                        node = (ListNode*)malloc(sizeof(ListNode));
                        node->val = pListHead->val;
                        if(q){
                                node->next = q;
                        }
                        q = node;
                        pListHead = pListHead->next;
                }
                return node;
        }
};

int main()
{

        ListNode* head = (ListNode*)malloc(sizeof(struct ListNode));
        head->val = 0;
        ListNode* p = head;
        for(int i = 1; i < 10; i++){
                ListNode* node = (ListNode*)malloc(sizeof(struct ListNode));
                node->val = i;
                p->next = node;
                p = p->next;
        }

        Solution s = Solution();
        ListNode* result = s.ReverList(head);
        cout<<"head:"<<endl;
        while(head){
                cout<<head->val<<",";
                head = head->next;
        }
        cout<<endl<<"result:"<<endl;
        while(result){
                cout<<result->val<<",";
                result = result->next;
        }
}

```




