#include<bits/stdc++.h>
using namespace std;



class Solution{
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int>s;
        vector<int>ans(n);
        for(int i =n-1;i>=0;i--){
            if(s.empty()){
                ans[i] = -1;
                s.push(arr[i]);
            }else{
                while(!s.empty()){
                    if(arr[i]<=s.top()){
                        s.pop();
                    }else{
                        break;
                    }
                }
                if(s.empty()){
                    ans[i]=-1;
                }else{
                    ans[i] = s.top();
                }
                s.push(arr[i]);
            }
        }
        return ans;
    } 
};
