#include<bits/stdc++.h>
using namespace std;



//RECURSIVE SOLUTION
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int recursion(int wt[],int val[] ,int W, int i,int n){
        if(i>=n){
            return 0;
        }
        
        if(W<=0){
            return  0;
        }
        
        if(W>=wt[i]){
            int ch1 =  val[i]+recursion(wt,val,W-wt[i],i+1,n);
            int ch2 = recursion(wt,val,W,i+1,n);
            return max(ch1,ch2);
        }else{
            return recursion(wt,val,W,i+1,n);
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return recursion (wt,val,W,0,n);
    }
};



//RECURSIVE + MEMOIZATION SOLUTION

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001];
    int recursion(int W,int *wt,int *val,int n,int i){
        if(i>=n){
            return 0;
        }
        
        if(dp[i][W]!=-1){
            return dp[i][W];
        }
        if(W>=wt[i]){
            int ch1 = val[i]+recursion(W-wt[i],wt,val,n,i+1);
            int ch2 = recursion(W,wt,val,n,i+1);
            return dp[i][W]=max(ch1,ch2);
        }else{
            return dp[i][W]=recursion(W,wt,val,n,i+1);
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       for(int i =0;i<=n;i++){
           for(int j =0;j<=W;j++){
               dp[i][j]=-1;
           }
       }
       return recursion(W,wt,val,n,0);
    }
};


//TABULATION
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,0));
       
       for(int i =1;i<=n;i++){
           for(int j =1;j<=W;j++){
               if(wt[i-1]>j){
                   dp[i][j]=dp[i-1][j];
               }else if(wt[i-1]<=j){
                   dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
               }
           }
       }
       return dp[n][W];
    }
};