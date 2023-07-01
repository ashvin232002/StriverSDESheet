#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i =0;i<strs[0].size();i++){
            bool match = true;
            char ch = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(strs[j].size() <i || ch != strs[j][i] ){
                    match = false;
                    break;
                }
            }
            if(match){
                ans += strs[0][i];
            }else{
                break;
            }
        }
        return ans;
    }
};