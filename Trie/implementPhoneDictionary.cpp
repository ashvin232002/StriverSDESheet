#include<bits/stdc++.h>
using namespace std;

//first approach using the backtracking and recursion
/*
class Solution {
public:
    void recursion(vector<string>& ans,string temp[] , string digits , int i,string& curr){
        if(i>=digits.size()){
            ans.push_back(curr);
            return;
        }

        int ch  =  digits[i]-'0';

        for(int k =0;k<temp[ch].size();k++){
            curr.push_back(temp[ch][k]);
            recursion(ans,temp,digits,i+1,curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }

        vector<string>ans;
        string temp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string curr="";
        recursion(ans,temp,digits,0,curr);
        return ans;
    }
};

*/
