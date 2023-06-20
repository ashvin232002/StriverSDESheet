#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recursion(vector<int>& nums,set<vector<int>>&s,int i,vector<int>&temp){
        if(i==nums.size()){
            s.insert(temp);
            return;
        }
        
        recursion(nums,s,i+1,temp);
        temp.push_back(nums[i]);
        recursion(nums,s,i+1,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        
        recursion(nums,s,0,temp);
        vector<vector<int>>ans;
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};