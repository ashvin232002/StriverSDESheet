#include<bits/stdc++.h>
using namespace std;

class node{
    public:
       int data;
       node* left;
       node* right;

    node(int data){
        this->data  =  data;
        this->left =  NULL;
        this->right =  NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter The data:"<<endl;
    int data ;
    cin>>data;

    root =  new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter The data for the inserting in the left part"<<endl;
    root->left  =  buildTree(root->left);

    cout<<"Enter The data for inserting in the right part"<<endl;
    root->right  =  buildTree(root->right);
}


void levelOrderTraversal(node* root){
    queue<node*>q;

    q.push(root);
    while(!q.empty()){
        int size =  q.size();
        while(size--){
            auto top = q.front();
            q.pop();
            cout<<top->data<<" ";

            if(top->left !=NULL){
                q.push(top->left);
            }
            if(top->right !=NULL){
                q.push(top->right);
            }
        }
        cout<<endl;
    }
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}


int main(){
     
    node* root  = NULL;
    root =  buildTree(root);

    levelOrderTraversal(root);

    cout<<"Printing The Inorder Traversal "<<endl;
    inorder(root);

    cout<<"Printing The Preorder Traversal "<<endl;
    preorder(root);

    cout<<"Printing The Postorder Traversal "<<endl;
    postorder(root);

    
    return  0;

}