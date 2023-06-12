#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int i ,int j  ,vector<vector<int>>& dp,int n,int m){
        if(i>=n || j>=m){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ch1 =  recursion(i+1,j,dp,n,m);
        int ch2 = recursion(i,j+1,dp,n,m);
        return dp[i][j]=ch1+ch2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return recursion(0,0,dp,n,m);
    }
};


//The most Optimal Way t find The ans is To use The combination Concept 
//ans = (m+n-2)C(m-1) 
// or ans can be   ans  = (m+n-2)C(n-1) both will give the same ans

//Using Memoization Approach
class Solution {
public:
    int dp[110][110];
    int recursion(int n,int r){
         if(r==0){
             return 1;
         }
         if(n==r){
             return 1;
         }
         if(r==1){
             return n;
         }
         if(dp[n][r]!=-1){
             return dp[n][r];
         }
         int ans=0;
         ans+=recursion(n-1,r-1);
         ans+=recursion(n-1,r);
         return dp[n][r]=ans;
    }
    int uniquePaths(int m, int n) {
        for(int i =0;i<110;i++){
            for(int j =0;j<110;j++){
                dp[i][j]=-1;
            }
        }
        return recursion(n+m-2,m-1);
    }
};


// #define mod 10000000007

//Tabulation Solution
class Solution {
    int nCrModp(int n,int r){
     vector<vector<long long int >>dp(n+1,vector<long long int>(r+1));
        for(int i =0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i =1;i<=r;i++){
            dp[0][i]=0;
        }
        
        for(int i =1;i<=n;i++){
            for(int j =1;j<=r;j++){
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]);
            }
        }
        return dp[n][r];
    
    }
public:
    int uniquePaths(int m, int n) {
        return nCrModp(m+n-2,m-1);
    }
};