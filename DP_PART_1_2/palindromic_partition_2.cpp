#include<bits/stdc++.h>
using namespace std;


//RECURSIVE SOLUTION
class Solution {
public:
    bool isPalindrome(int i,int j,string &s){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }

    
    int recursion(int i,int n,string &s){
        if(i==n){
            return 0;
        }

        int ans  =  INT_MAX;
        for(int j =i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost  =  1+recursion(j+1,n,s);
                ans=min(ans,cost);
            }
        }
        return ans;
    }
    int minCut(string s) {
        int n = s.size();
        return recursion(0,n,s)-1;
    }
};


//RECURSION + MEMOIZATION
class Solution {
public:
    bool isPalindrome(int i,int j,string &s){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }

    int dp[2001];
    int recursion(int i,int n,string &s){
        if(i==n){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }
        int ans  =  INT_MAX;
        for(int j =i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost  =  1+recursion(j+1,n,s);
                ans=min(ans,cost);
            }
        }
        return dp[i]=ans;
    }

    
    int minCut(string s) {
        if(s.empty()){
            return 0;
        }
        int n = s.size();
        for(int i =0;i<2001;i++){
            dp[i]=-1;
        }
        return recursion(0,n,s)-1;
    }
};


//TABULATION SOLUTION
class Solution {
public:
    bool isPalindrome(int i,int j,string &s){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }

    

    int recursionTab(string s){
      int n = s.size();
      vector<int>dp(s.size()+2,0);

      for(int i =n-1;i>=0;i--){
         int ans  =  INT_MAX;
         for(int j =i;j<n;j++){
             if(isPalindrome(i,j,s)){
                int cost  =  1+dp[j+1];
                ans=min(ans,cost);
            }
         }
         dp[i]=ans;
      }
      return dp[0]-1;
    }
    int minCut(string s) {
        return recursionTab(s);
    }
};