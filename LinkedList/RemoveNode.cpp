
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            total++;
            temp=temp->next;
        }
        if(total==1){
            return NULL;
        }
        int count=total-n-1;
        if(count<0){
            return head->next;
        }
        temp=head;
        while(count>0){
            temp=temp->next;
            count--;
        }

        temp->next=temp->next->next;
        return head;
    }
};