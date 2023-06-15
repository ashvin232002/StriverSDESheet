
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==NULL){
            return head;
        }
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        // cout<<count<<endl;
        if(k>=count)k=k%count;
        // cout<<k<<endl;
        if(k==0){
            return head;
        }
        int val =  count-k-1;
        temp = head;
        while(val>0){
            temp = temp->next;
            val-=1;
        }
        ListNode* next ;
        next =  temp->next;
        temp->next = NULL;
        temp = next;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next =  head;
        return next;
    }
};