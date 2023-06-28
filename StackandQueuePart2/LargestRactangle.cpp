#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>mystack;
        
        
        for(int i =0;i<n;i++){
            if(mystack.empty()){
                left[i]=0;
                mystack.push(i);
            }else{
                while(!mystack.empty() && height[mystack.top()]>=height[i]){
                    mystack.pop();
                }
                left[i]=mystack.empty()?0:mystack.top()+1;
                mystack.push(i);
            }
        }
        
        while(!mystack.empty()){
            mystack.pop();
        }
        
        for(int i =n-1;i>=0;i--){
            if(mystack.empty()){
                right[i]=n-1;
                mystack.push(i);
            }else{
                while(!mystack.empty() && height[mystack.top()]>=height[i]){
                    mystack.pop();
                }
                right[i]=mystack.empty()?n-1:mystack.top()-1;
                mystack.push(i);
            }
        }
        
        int area = 0;
        for(int i =0;i<n;i++){
            area = max(area,(right[i]-left[i]+1)*height[i]);
        }
        return area;
    }
};