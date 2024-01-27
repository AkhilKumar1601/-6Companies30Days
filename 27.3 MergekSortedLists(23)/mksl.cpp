#include<iostream>
#include<vector>
#include<queue>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    class compare{
       public:
          bool operator()(ListNode* a,ListNode* b){
             return a -> val > b -> val;
          }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;

        for(int i = 0; i < lists.size(); i++){
            ListNode* topList = lists[i];
            if(topList != NULL)pq.push(topList);
        }

        ListNode* Head = NULL;
        ListNode* Tail = NULL;

        while(!pq.empty()){
            ListNode* topNode = pq.top();
            pq.pop();

            if(Head == NULL){
                Head = topNode;
                Tail = topNode;
            }
            else{
                Tail -> next = topNode;
                Tail = topNode;
            }

            if(Tail -> next != NULL)pq.push(Tail -> next);
        }

        return Head;
    }
};