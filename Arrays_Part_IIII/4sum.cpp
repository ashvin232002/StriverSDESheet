#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        #define ll long long
       
        int n= nums.size();
        vector<vector<int>> v;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++){
           for(int j=i+1; j<n-2; j++){
               int k=j+1;
               int l=n-1;
                  while(k<l){
                      long long int sum=nums[i];
                      sum+=nums[j];
                      sum+=nums[k];
                      sum+=nums[l];
                        if(sum==target){
                        st.insert({nums[i],nums[j],nums[k],nums[l]});
                                k++;
                                l--;
                        }
                        else if(sum>target){
                                l--;
                        }
                        else if(sum<target){
                            k++;
                        }
                  }
           }
        }
        for(auto it : st){
            v.push_back(it);
        }
        return v;
        }
};