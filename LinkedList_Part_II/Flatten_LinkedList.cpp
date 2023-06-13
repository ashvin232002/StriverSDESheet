


#include<bits/stdc++.h>
using namespace std;
/* Node structure  used in the program
*/
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};


/*  Function which returns the  root of 
    the flattened linked list. */

Node* merge(Node* A ,Node* B){
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    while(A && B){
        if(A->data < B->data){
            temp->bottom = A;
            A = A->bottom;
            temp = temp->bottom;
        }else{
            temp->bottom = B;
            B= B->bottom;
            temp = temp->bottom;
        }
    }
    if(A) temp->bottom = A;
    if(B) temp->bottom = B;
    return ans->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   Node* res = NULL;
   Node* temp = root;
   while(temp){
       res = merge(res,temp);
       temp = temp->next;
   }
   return res;
}