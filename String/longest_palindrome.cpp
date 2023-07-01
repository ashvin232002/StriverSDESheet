#include<bits/stdc++.h>
using namespace std;



// Approach 1 
//try for odd length palindrome
//try for even length palindrome
class Solution {
public:
    string longestPalindrome(string s) {
       int maxLen = 0;
       string ans = "";
       for(int i =0;i<s.size(); i++){
           int l = i;
           int r  =i;
           while(l>=0 && r<s.size() && s[l]==s[r]){
               if(maxLen<r-l+1){
                   maxLen  = r-l+1;
                   ans=s.substr(l,r-l+1);
               }
               l--;
               r++;
           }

           l= i;
           r =i+1;
           while(l>=0  && r<s.size() && s[l]==s[r]){
               if(maxLen < r-l+1){
                   maxLen =  r-l+1;
                   ans =  s.substr(l,r-l+1);
               }
               l--;
               r++;
           }
       }
       return ans;
    }
};


//dp+ memoization
class Solution {
public:
    int dp[1001][1001];

    bool isPalindrome(string &s ,int a ,int b){
        if(a>=b){
            return true;
        }
        if(dp[a][b]!=-1){
            return dp[a][b];
        }
        return dp[a][b] = (s[a] == s[b] && isPalindrome(s,a+1,b-1));
    }
    string longestPalindrome(string s) {
        memset(dp,-1,sizeof(dp));
        int size  =  s.size();

        for(int len = size ; len>=1 ;len--){
            for(int start = 0;start<=size-len ;start++){
                int end = start + len - 1;
				if (isPalindrome(s, start, end)) {
					return s.substr(start, len);
                }
            }
        }
        return "";
    }
};


//dp + tabulation
class Solution {
public:
    string longestPalindrome(string s) {
       int n = s.size();
       vector<vector<int>>dp(n,vector<int>(n));
      
       string ans;
       int maxLen = 0;
       for(int diff = 0;diff<n;diff++){
           int i =0;
           int j =i+diff;
           while(j<n){
               if(i==j){
                   dp[i][j]=1;
               }
               else if(diff==1){
                   if(s[i]==s[j]){
                       dp[i][j]=2;
                   }else{
                       dp[i][j]=0;
                   }
               }else{
                   if(s[i]==s[j] && dp[i+1][j-1]>0)
                       dp[i][j]=dp[i+1][j-1]+2;
                   
               }
               if(dp[i][j]){
                   if(j-i+1>maxLen){
                       maxLen = j-i+1;
                       ans = s.substr(i,maxLen);
                   }
               }
               i++;
               j++;
           }
       }
       return ans;
    }
};