



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

void deleteNode(ListNode* node) {
        if (node == NULL) {
            return;
        }

        ListNode *previousNode = NULL;
        while (node->next != NULL) {
            node->val = node->next->val;

            previousNode = node;
            node = node->next;
        }

        if (previousNode != NULL) {
            previousNode->next = NULL;
            delete(node);
            node = NULL;
        }
}