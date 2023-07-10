#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int recursion(string s1,string s2,int i,int j,vector<vector<int>>& dp){
        if(i==s1.size() || j==s2.size()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }  

        int ans = 0;
        if(s1[i]==s2[j]){
            ans = 1+recursion(s1,s2,i+1,j+1,dp);
        }else{
             ans=max(recursion(s1,s2,i+1,j,dp),recursion(s1,s2,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
     

    int solveTab(string s1,string s2){
        int n = s1.size();
        int m = s2.size();
         vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
         for(int i = s1.size()-1;i>=0;i--){
             for(int j =s2.size()-1;j>=0;j--){
                 int ans = 0;
                 if(s1[i]==s2[j]){
                    ans = 1+dp[i+1][j+1];
                }else{
                    ans=max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;
             }
         }
         return dp[0][0];

    }
    int longestCommonSubsequence(string text1, string text2) {
      
        // return recursion(text1,text2,0,0,dp);
        return solveTab(text1,text2);
    }
};