
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i= 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>temp;
        for(auto it:mp){
            temp.push_back({it.second,it.first});
        }
        sort(temp.begin(),temp.end(),[&](pair<int,int>&a,pair<int,int>&b){
            return a.first>b.first;
        });

        vector<int>ans;
        for(int i =0;i<k;i++){
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};