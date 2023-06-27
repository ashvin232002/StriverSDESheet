#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int>q;
    int start ;
    int end  ;
    MyStack() {
        end = 0;
    }
    
    void push(int x) {
        end++;
        q.push(x);
    }
    
    int pop() {
        end--;
        queue<int>q1;
        int k =end;
        while(k>0){
            q1.push(q.front());
            q.pop();
            k--;
        }
        int ans  =  q.front();
        q.pop();
        q=q1;
        return ans;
    }
    
    int top() {
        queue<int>q1;
        while(q.size()>1){
            q1.push(q.front());
            q.pop();
        }
        int ans  =  q.front();
        q1.push(q.front());
        q.pop();
        q=q1;
        return ans;
    }
    
    bool empty() {
        if(end==0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */



//more easy way
class MyStack {
public:
    queue<int>q;
    
    MyStack() {
       
    }
    
    void push(int x) {
        int s  =  q.size();
        q.push(x);
        for(int i =0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
         if(q.size()==0){
             return true;
         }
         return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */