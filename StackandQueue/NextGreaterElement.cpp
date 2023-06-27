
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& arr) {
        // code here
             vector<int>v(N);
        stack<int>st;
        for(int i=N-1;i>=0;i--){
            st.push(arr[i]);
        }
        for(int i=N-1;i>=0;i--){
            while(!st.empty() && arr[i]>=st.top()){
                st.pop();
            }
            if(st.empty()==true){
                v[i]=(-1);
            }
            else{
                v[i]=(st.top());
            }
            st.push(arr[i]);
        }
        
        return v;
    }
};
