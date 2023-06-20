#include<bits/stdc++.h>
using namespace std;

//runTime  : 0ms 
class Solution {
public:

    void recursion(vector<int>& candidates , vector<vector<int>>& ans ,  vector<int>& temp ,int i ,int target){
        if(target<0 || i>=candidates.size()){
            return;
        }
        if(target==0){
            ans.push_back(temp);
            return;
        }

        recursion(candidates,ans,temp,i+1,target);
        temp.push_back(candidates[i]);
        recursion(candidates,ans,temp,i,target-candidates[i]);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        recursion(candidates,ans,temp,0,target);
        return ans;
    }
};

