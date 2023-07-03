#include<bits/stdc++.h>
using namespace std;

//TLE SOLUTION 
//RECURSION + MEMOIZATION
class Solution {
public:
    int dp[501][501];
    int recursion(string s1,string s2,int i,int j){
        if(i==s1.size()||j==s2.size()){
            return 0;
        }
        
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=1+recursion(s1,s2,i+1,j+1);
        }else{
            int ch1 = recursion(s1,s2,i+1,j);
            int ch2 = recursion(s1,s2,i,j+1);
            return dp[i][j]=max(ch1,ch2);
        }
    }
    int minInsertions(string s1) {
        for(int i =0;i<501;i++){
            for(int j =0;j<501;j++){
                dp[i][j]=-1;
            }
        }
        string s2 =s1;
        reverse(s2.begin(),s2.end());
        
        int ans =recursion(s1,s2,0,0);
        
        return s1.size()-ans;
    }
};



//TABULATION SOLUTION
class Solution {
public:
    
    int minInsertions(string s1) {
      int n = s1.size();
        string s2=s1;
        reverse(s2.begin(),s2.end());
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return s1.size()-dp[n][m];
    }
};