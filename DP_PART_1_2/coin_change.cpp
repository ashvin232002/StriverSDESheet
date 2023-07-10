

#include<bits/stdc++.h>
using namespace std;


//MEMOIZATION SOLUTION
class Solution {
public:
    int dp[10001];
    int recursion(vector<int>& coins, int amount){
        if(amount<0){
            return INT_MAX;
        }
        
        if(amount==0){
            return 0;
        }

        if(dp[amount]!=-1){
            return dp[amount];
        }
        int ans =  INT_MAX;

        for(int i =0;i<coins.size();i++){
            int curr  =  recursion(coins,amount-coins[i]);

            if(curr!=INT_MAX){
                ans=min(ans,curr+1);
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
       for(int i =0;i<10001;i++){
           dp[i]=-1;
       }
       int ans  =  recursion(coins,amount);
       if(ans==INT_MAX)return -1;
       return ans;
    }
};


//TABULATION
class Solution {
public:
    int Tabulation(vector<int>& nums,int amount){
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;

        for(int i =1;i<=amount;i++){ //basically trying for the every possible amount
            for(int j =0 ;j<nums.size();j++){
                if(i-nums[j]>=0 && dp[i-nums[j]]!=INT_MAX){
                    dp[i]=min(dp[i],dp[i-nums[j]]+1);
                }
            }
        }

        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        return Tabulation(coins,amount);
    }
};