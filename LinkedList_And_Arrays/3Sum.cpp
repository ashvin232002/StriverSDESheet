
#include<bits/stdc++.h>
using namespace std;


//TC =  O(N^2 logn)
//SC =  O(N^2 + N^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
         sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size()-2;i++){
           int j = i+1;
           int k = nums.size()-1;

           while(j<k){
               if(nums[i]+nums[j]+nums[k]==0){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
               }else if(nums[i]+nums[j]+nums[k]>0){
                   k--;
               }else{
                   j++;
               }
           }
        }

        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};


//TC =  O(N^2 logn)
//sc = O(N^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        if(n<3)return {};
        
        for(int i = 0;i<n-2;i++){
            if(i==0 ||(i>0 && nums[i] != nums[i-1])){
             int j = i+1;
             int k = n-1;
                while(j<k){
                    int target = 0-nums[i];
                    if(nums[j]+nums[k] == target){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        ans.push_back(temp);
                        
                        while(j<k && nums[j]==nums[j+1])j++;
                        while(j<k && nums[k]==nums[k-1])k--;
                        j++;
                        k--;
                    }else if(nums[j]+nums[k]>target){
                        k--;
                    }else{
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};