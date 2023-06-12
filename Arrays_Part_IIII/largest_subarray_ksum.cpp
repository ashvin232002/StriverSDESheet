#include<bits/stdc++.h>
using namespace std;



class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        map<int,int>mp;
        int sum = 0;
        int ans = 0;
        mp[0]=-1;
        for(int i =0;i<n;i++){
            sum+=A[i];
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }else{
                ans=max(ans,i-mp[sum]);
            }
        }
        return ans;
    }
};