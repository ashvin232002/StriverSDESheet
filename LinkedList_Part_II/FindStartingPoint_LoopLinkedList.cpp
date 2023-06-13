











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
    ListNode *detectCycle(ListNode *head) {
      ListNode* slow  = head;
      ListNode* fast = head;

      while(fast!=NULL && fast->next!=NULL){
          slow=  slow->next;
          fast= fast->next->next;

          if(fast==slow){
              break;
          }
      }
      if(fast==NULL || fast->next==NULL){
          return NULL ;
      }
      if(slow==head){
          return slow;
      }
      slow=head;
      while(slow->next!=fast->next){
          slow=slow->next;
          fast=fast->next;
      }
      return slow->next;
    }
};