#复杂链表的复制

##问题：
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）。

##思路：
这个链表实际上已经可以看成有向图了，按照有向图负责的方法，先复制节点，再复制节点的关系(边)。

##Code：
```C++
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
```

附上一个有向图复制的代码
```C++
class Solution {
    map<RandomListNode*, RandomListNode*> mp;
    set<RandomListNode*> vis;
    void dfs1(RandomListNode* u){
        if(u && mp.find(u) == mp.end()) {
            mp[u] = new RandomListNode(u -> label);
            dfs1(u -> next);
            dfs1(u -> random);
        }
    }
    void dfs2(RandomListNode* u){
        if(u && vis.find(u) == vis.end()){
            if(u -> next) mp[u] -> next = mp[u -> next];
            if(u -> random) mp[u] -> random = mp[u -> random];
            vis.insert(u);
            dfs2(u -> next);
            dfs2(u -> random);
        }
    }
public:
    RandomListNode* Clone(RandomListNode* pHead){
        if(!pHead) return NULL;
        mp.clear();
        vis.clear();
        dfs1(pHead);
        dfs2(pHead);
        return mp[pHead];
    }
};
```




