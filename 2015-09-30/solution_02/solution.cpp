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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
		ListNode* p1;
		ListNode* p2;
		ListNode* p = NULL;
		ListNode* q;
		ListNode* pHead = NULL;
		p1 = pHead1;
		p2 = pHead2;
		
		while(p1 && p2){
			q = (ListNode*)malloc(sizeof(ListNode));
			if(p1->val <= p2->val){
				q->val = p1->val;
				p1 = p1->next;
			}else{
				q->val = p2->val;
				p2 = p2->next;
			}

			if(!p){
				pHead = p = q;
			}else{
				p->next = q;
				p = q;
			}
		}

		while(p1){
			q = (ListNode*)malloc(sizeof(ListNode));
			q->val = p1->val;
			if(!p){
				pHead = p = q;
			}else{
				p->next = q;
				p = q;
			}
			p1 = p1->next;
		}

		while(p2){
			q = (ListNode*)malloc(sizeof(ListNode));
			q->val = p2->val;
			if(!p){
				pHead = p = q;
			}else{
				p->next = q;
				p = q;
			}
			p2 = p2->next;
		}

		return pHead;

	}
};

int main()
{

	ListNode* pHead1 = (ListNode*)malloc(sizeof(struct ListNode));
	pHead1->val = 0;
	ListNode* p = pHead1;
	for(int i = 2; i < 10; i+=2){
		ListNode* node = (ListNode*)malloc(sizeof(struct ListNode));
		node->val = i;
		p->next = node;
		p = p->next;
	}

	ListNode* pHead2 = (ListNode*)malloc(sizeof(struct ListNode));
	pHead2->val = 1;
	p = pHead2;
        for(int i = 1; i < 12; i+=2){
		ListNode* node = (ListNode*)malloc(sizeof(struct ListNode));
		node->val = i;
		p->next = node;
		p = p->next;
	}


	Solution s = Solution();
	ListNode* result = s.Merge(pHead1,pHead2);
	

	cout<<"p1:"<<endl;
	while(pHead1){
		cout<<pHead1->val<<",";
		pHead1 = pHead1->next;
	}

	
	cout<<endl<<"p2:"<<endl;
	while(pHead2){
		cout<<pHead2->val<<",";
		pHead2 = pHead2->next;
	}
	
	cout<<endl<<"result:"<<endl;
	while(result){
		cout<<result->val<<",";
		result = result->next;
	}
}

