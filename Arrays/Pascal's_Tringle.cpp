#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i =1;i<=numRows;i++){
            vector<int>v(i);
            vector<int>prev;
            if(i>1){
               prev = ans.back();
            }
            v[0]=1;
            v[v.size()-1]=1;
           
            if(i>=2){
                for(int j =1;j<=v.size()-2;j++){
                    v[j]=prev[j-1]+prev[j];
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};