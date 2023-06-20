#include<bits/stdc++.h>
using namespace std;


//Time Limit Excceeded
class Solution {
public:
    void recursion(vector<int>& candidates,set<vector<int>>& s,int target,int i,vector<int>& v){
        if(i>=candidates.size() && target!=0){
            return ;
        }
        if(target<0){
            return;
        }

        if(target==0){
            s.insert(v);
            return;
        }
        recursion(candidates,s,target,i+1,v);
        v.push_back(candidates[i]);
        recursion(candidates,s,target-candidates[i],i+1,v);
        v.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>s;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        recursion(candidates,s,target,0,v);
        vector<vector<int>>ans;
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};







class Solution {
public:
    vector<vector<int>> result;
    
    void helper(vector<int> &candidates, vector<int> cur, int sum, int target, int start){
        if(sum==target){
            result.push_back(cur);
            return ;
        }
        
        for(int i=start;i<candidates.size();i++){
            if(i==start || candidates[i]!=candidates[i-1]){
                if(sum<=target){
                    cur.push_back(candidates[i]);
                    helper(candidates, cur, sum+candidates[i], target, i+1);
                    cur.pop_back();
                }
            }
        }
        
        return ;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        helper(candidates, cur, 0, target, 0);
        return result;
    }
};