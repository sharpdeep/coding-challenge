#两个链表的第一个公共结点

##问题：
输入两个链表，找出它们的第一个公共结点。

##思路：
两个链表有公共节点，那么在第一个公共节点之后的部分两个链表都是共用的，此部分长度相同。那么唯一长度不同就是第一个公共节点的前半部分。

所以只需要计算出两个链表的长度，让长的链表先跑完长出来的那部分，然后两个链表同时前进，当节点相同时，说明找到了第一个公共节点了。

##Code：
```C++
#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    int GetListLen(ListNode* p){
	int len = 0;	
	while(p){
		p = p->next;
		len++;	
	}
	return len;
    }

    ListNode* ListStep(ListNode* p, int step){
	while(step--){
		p = p->next;	
	}
	return p;
    }

    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        
        if(!pHead1 || !pHead2){
            return NULL;
        }
        
        int len1 = GetListLen(pHead1);
        int len2 = GetListLen(pHead2);
        
        if(len1 > len2){
            pHead1 = ListStep(pHead1,len1-len2);
        }else{
	    pHead2 = ListStep(pHead2,len2-len1);
        }
        
        while(pHead1){
            if(pHead1 == pHead2){
                return pHead1;
            }
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        
        return NULL;
    }
};

int main()
{
	ListNode* pHead1 = (ListNode*)malloc(sizeof(struct ListNode));
	pHead1->val = 0;
	ListNode* pHead2 = (ListNode*)malloc(sizeof(struct ListNode));
	pHead2->val = 0;

	
    	ListNode* p = pHead1;
	ListNode* q = pHead2;

    	for(int i = 1; i < 10; i++){
        	ListNode* node = (ListNode*)malloc(sizeof(struct ListNode));
        	node->val = i;
        	p->next = node;
		q->next = node;
        	p = p->next;
		q = q->next;
    	}

	Solution s = Solution();
	ListNode* result = s.FindFirstCommonNode(pHead1,pHead2);
	
	cout<<result->val<<endl;
}
```