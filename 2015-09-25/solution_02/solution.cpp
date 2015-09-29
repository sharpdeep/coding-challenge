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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
		ListNode* pre = pListHead;
		ListNode* cur = pListHead;
		int distance = 0;

		if(pListHead == NULL){
			return NULL;
		}

		for(int i = 0; i < k; i++){
			if(!pre){
				return NULL;
			}
			pre = pre -> next;
		}

		while(pre){
			pre = pre->next;
			cur = cur->next;
		}

		return cur;

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
	ListNode* result = s.FindKthToTail(head,2);
	cout<<result->val<<endl;
}

