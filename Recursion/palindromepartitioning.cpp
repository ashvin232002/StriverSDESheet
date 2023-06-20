#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s,int i,int j){
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
    void recursion(string s,vector<string>&temp,vector<vector<string>>& ans,int i){
        if(i>=s.size()){
                ans.push_back(temp);
            return ;
        }
        for(int curr=i;curr<s.size();curr++){
            if(isPalindrome(s,i,curr)){
                temp.push_back(s.substr(i,curr-i+1));
                recursion(s,temp,ans,curr+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        recursion(s,temp,ans,0);
        return ans;
    }
};