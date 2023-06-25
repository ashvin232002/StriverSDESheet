#include<bits/stdc++.h>
using namespace  std;


class Solution {
public:
    bool isPossible(vector<int>& a,int n,int k,int mid){
        int count =1;
        int prev  =0;
        for(int  i =0;i<n;i++){
            if(a[i]-a[prev] <mid){
                continue;
            }else{
                count++;
                if(count==k){
                    return true;
                }
                prev =i;
            }
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int low  = 0;
        int maxi =-1;
        for(int i =0;i<n;i++){
            maxi =max(maxi,stalls[i]);
        }
        int high = maxi ;
        int ans  = -1;
        
        
        while(low<=high){
            int mid  =  low+(high-low)/2;
            if(isPossible(stalls,n,k,mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};