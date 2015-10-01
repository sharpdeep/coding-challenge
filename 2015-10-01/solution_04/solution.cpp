#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
    map<RandomListNode*,RandomListNode*> nodeMap;
public:
    void CloneNode(RandomListNode* pHead){
        RandomListNode* p = pHead;
        while(p){
            nodeMap[p] = new RandomListNode(p->label);
            p = p->next;
        }
    }
    
    void CloneRelate(RandomListNode* pHead){
        RandomListNode* p = pHead;
        while(p){
            nodeMap[p]->next = nodeMap[p->next];
            nodeMap[p]->random = nodeMap[p->random];
            p = p->next;
        }
    }
    
    
    RandomListNode* Clone(RandomListNode* pHead)
    {
		if(!pHead){
            return NULL;
        }
        
        CloneNode(pHead);
        CloneRelate(pHead);
        
        return nodeMap[pHead];
    }
};

int main()
{
	RandomListNode* head = new RandomListNode(0);
	RandomListNode* p = head;

	for(int i = 1; i < 10; i++){
		RandomListNode* node1 = new RandomListNode(i);
		RandomListNode* node2 = new RandomListNode(++i);
		
		p->next = node1;
		node1->next = node2;
		p->random = node2;
		p = node2;
	}

	Solution s = Solution();
	RandomListNode* result = s.Clone(head);

	cout<<"the random link of the head of copy-list is:"<<result->random->label<<endl;
}
