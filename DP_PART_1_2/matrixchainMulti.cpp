#include<bits/stdc++.h>
using namespace std;



//RECURSION SOLUTION
class Solution{
public:
    int recursion(int i,int j,int arr[]){
        if(i==j){
            return  0 ;
        }
        
        int ans  =  INT_MAX;
        for(int k =i;k<j;k++){
            int steps  =  arr[i-1]*arr[k]*arr[j]+recursion(i,k,arr)+recursion(k+1,j,arr);
            ans =  min(ans,steps);
        }
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return recursion(1,N-1,arr);
    }
};




//RECURSION + MEMOIZATION
class Solution{
public:
    int dp[101][101];
    int recursion(int i,int j,int arr[]){
        if(i==j){
            return  0 ;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        
        int ans  =  INT_MAX;
        for(int k =i;k<j;k++){
            int steps  =  arr[i-1]*arr[k]*arr[j]+recursion(i,k,arr)+recursion(k+1,j,arr);
            ans =  min(ans,steps);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        for(int i =0;i<101;i++){
            for(int j =0;j<101;j++){
                dp[i][j]=-1;
            }
        }
        return recursion(1,N-1,arr);
    }
};





//TABULATION
class Solution{
public:
    int recursionTab(int arr[],int n){
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        for(int i =0;i<n;i++){
            dp[i][i]=0;
        }
        
        for(int i =n-1;i>=1;i--){
            for(int j =i+1;j<n;j++){
                int ans  = INT_MAX;
                for(int k =i;k<j;k++){
                    int steps =  arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    ans=min(ans,steps);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n-1];
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        
        return recursionTab(arr,N);
    }
};