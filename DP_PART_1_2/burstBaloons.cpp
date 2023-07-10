#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[305][305];
    int recursion(vector<int>& nums,int i,int j){
        if(i>j)return 0;


        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans  =  INT_MIN;
        for(int  index= i;index<=j;index++){
             int curr  =  nums[index]*nums[i-1]*nums[j+1] + recursion(nums,i,index-1)+recursion(nums,index+1,j);
             ans=max(ans,curr);
        }
        return  dp[i][j]= ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n =  nums.size();
        for(int i = 0;i<305;i++){
            for(int j =0;j<305;j++){
                dp[i][j]=-1;
            }
        }
        return recursion(nums,1,n-2);
    }
};