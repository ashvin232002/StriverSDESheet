#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[501][501];
    int recursion(string s1,string s2,int i,int j){
        if(i==s1.size() && j==s2.size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==s1.size()){
            return dp[i][j]=s2.size()-j;
        }
        
        if(j==s2.size()){
            return dp[i][j]=s1.size()-i;
        }
        
        if(s1[i]==s2[j]){
            return dp[i][j]=recursion(s1,s2,i+1,j+1);
        }else{
            int ch1 = recursion(s1,s2,i,j+1);
            int ch2 = recursion(s1,s2,i+1,j);
            int ch3 = recursion(s1,s2,i+1,j+1);
            
            return dp[i][j]= min(ch1,min(ch2,ch3))+1;
        }
    }
    int minDistance(string s1, string s2) {
        for(int i =0;i<501;i++){
            for(int j =0;j<501;j++){
                dp[i][j]=-1;
            }
        }
        return recursion(s1,s2,0,0);
    }
};






class Solution {
public:
    
    int recursion(string s1,string s2){

        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));

        
        for(int j=0;j<s2.size();j++){
            dp[s1.size()][j]=s2.size()-j;
        }
        for(int i=0;i<s1.size();i++){
            dp[i][s2.size()]=s1.size()-i;
        }
        
        for(int i =s1.size()-1;i>=0;i--){
            for(int j =s2.size()-1;j>=0;j--){
                int ans = 0;
                if(s1[i]==s2[j]){
                    ans=dp[i+1][j+1];
                }else{
                        int ch1 = dp[i][j+1];
                        int ch2 = dp[i+1][j];
                        int ch3 = dp[i+1][j+1];
                        
                        ans= min(ch1,min(ch2,ch3))+1;

                }
                dp[i][j]=ans;
            }
            
        }
        return dp[0][0];
        
    }
    int minDistance(string s1, string s2) {
        
        return recursion(s1,s2);
    }
};