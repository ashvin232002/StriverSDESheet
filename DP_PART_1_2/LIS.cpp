#include<bits/stdc++.h>
using namespace std;


//Memoization Solution
class Solution {
public:
    int dp[2501][2501];
    int recursion(vector<int>& nums,int i,int prev){
        if(i==nums.size()){
            return 0;
        }

        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        if(prev==-1 || nums[i]>nums[prev]){
            int ch1 = 1+ recursion(nums,i+1,i);
            int ch2 = recursion(nums,i+1,prev);
            return dp[i][prev+1]= max(ch1,ch2);
        }else{
            return dp[i][prev+1]=recursion(nums,i+1,prev);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        for(int i =0;i<2501;i++){
            for(int j =0;j<2501;j++){
                dp[i][j]=-1;
            }
        }
        return recursion(nums,0,-1);
    }
};



//BRUTE FORCE + TABULATION
class Solution {
public:
    int recursion(vector<int>& nums,int prev,int i){
        if(i>=nums.size()){
            return 0;
        }


        if(prev==-1 || nums[prev]<nums[i]){
            int ch1 = 1+recursion(nums,i,i+1);
            int ch2 = recursion(nums,prev,i+1);
            return max(ch1,ch2);
        }else{
            return recursion(nums,prev,i+1);
        }
    }

    int recursionTab(vector<int>&nums){
         int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
         
         
         for(int i=n-1;i>=0;i--){
             for(int prev=i-1;prev>=-1;prev--){
                 
                 if(prev==-1 || nums[prev]<nums[i]){
                    int ch1 = 1+ dp[i+1][i+1];
                    int ch2 = dp[i+1][prev+1];

                    dp[i][prev+1]=max(ch1,ch2);
                }else{
                    dp[i][prev+1]=dp[i+1][prev+1];
                }
             }
         }
        return dp[0][0];
     }

    int lengthOfLIS(vector<int>& nums) {
        return recursionTab(nums);
    }
};


//variation Problems 
/*
1. Russian Doll Envolpment
2. Maximum Height by Rearranging Cuboids

*/