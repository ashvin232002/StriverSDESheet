

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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        int carry =0;
        ListNode* ans  = new ListNode(-1);
        ListNode* temp = ans;
        while(list1!=NULL && list2!=NULL){
            int curr   = list1->val;
            curr      += list2->val;
            curr+=carry;
            if(curr<=9){
                ans->next =  new ListNode(curr);
                ans = ans->next;
                list1=list1->next;
                list2=list2->next;
                carry = 0;
            }else{
                int div =  curr/10;
                int mod  = curr%10;
                carry=div;
                ans->next =  new ListNode(mod);
                ans = ans->next;
                list1=list1->next;
                list2=list2->next;
            }
        }

        while(list1!=NULL){
            int curr = list1->val+carry;
            if(curr<=9){
                ans->next =  new ListNode(curr);
                ans = ans->next;
                list1=list1->next;
                carry = 0;
            }else{
                int div =  curr/10;
                int mod  = curr%10;
                carry=div;
                ans->next =  new ListNode(mod);
                ans = ans->next;
                list1=list1->next;
            }
        }
        while(list2!=NULL){
            int curr = list2->val+carry;
            if(curr<=9){
                ans->next =  new ListNode(curr);
                ans = ans->next;
                list2=list2->next;
                carry = 0;
            }else{
                int div =  curr/10;
                int mod  = curr%10;
                carry=div;
                ans->next =  new ListNode(mod);
                ans = ans->next;
                list2=list2->next;
            }
        }

        if(carry>0){
             ans->next =  new ListNode(carry);
        }
        return temp->next;
    }
};