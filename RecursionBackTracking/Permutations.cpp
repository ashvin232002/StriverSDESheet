#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    void recursion(vector<int>& nums,vector<vector<int>>& ans,int i ){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int index=i;index<nums.size();index++){
            swap(nums[index],nums[i]);
            recursion(nums,ans,i+1);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        recursion(nums,ans,0);
        return ans;
    }
};