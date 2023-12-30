#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        
        vector<int>left(n,-1);
        vector<int>right(n,n);
        
        stack<int>s;
        int i = 0;
        while(i<n){
            if(s.empty()){
                s.push(i);
                i++;
            }else{
                while(!s.empty()){
                    if(!s.empty()  && arr[s.top()]>=arr[i]){
                        s.pop();
                    }else{
                        break;
                    }
                }
                
                if(s.empty()){
                    s.push(i);
                    i++;
                }else{
                    left[i]=s.top();
                    s.push(i);
                    i++;
                }
            }
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        i=n-1;
        while(i>=0){
            if(s.empty()){
                s.push(i);
                i--;
            }else{
                while(!s.empty()){
                    if(!s.empty()  && arr[s.top()]>=arr[i]){
                        s.pop();
                    }else{
                        break;
                    }
                }
                if(s.empty()){
                    s.push(i);
                    i--;
                }else{
                    right[i]=s.top();
                    s.push(i);
                    i--;
                }
            }
        }
        
        vector<int>len(n);
        for(int i = 0;i<n;i++){
            if(left[i]==-1){
                len[i]=right[i];
            }else{
                len[i]=(right[i]-left[i]-1);
            }
        }
        
        vector<int>ans(n,INT_MIN);
        for(int  i = 0 ;i<n;i++){
            ans[len[i]-1] = max(ans[len[i]-1],arr[i]);
        }
        
        for(int i =n-2;i>=0;i--){
            ans[i]=max(ans[i],ans[i+1]);
        }
        return ans;
    }
};
