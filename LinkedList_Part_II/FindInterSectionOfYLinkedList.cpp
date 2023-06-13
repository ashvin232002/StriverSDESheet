
#include<bits/stdc++.h>
using namespace std;


//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}   
    ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        if(temp1==NULL || temp2==NULL)return NULL;
        while(temp1 != NULL && temp2 != NULL && temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
            
            if(temp1 == temp2){
                return temp1;
            }
            
            if(temp1==NULL){
                temp1 = headA;
            }
            if(temp2 == NULL){
                temp2 = headB;
            }
        }
        return temp1;
    }
};