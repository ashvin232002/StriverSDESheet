#include<bits/stdc++.h>
using namespace  std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end(),[&](vector<int>& a,vector<int>&b){
              if(a[0]==b[0]){
                   a[1]<b[1];
              }
              return a[0]<b[0];
        });

         ans.push_back(intervals[0]);
         for(int i =1;i<intervals.size();i++){
             if(intervals[i][0]<=ans.back()[1]){
                 vector<int>temp = ans.back();
                 ans.pop_back();
                 ans.push_back({temp[0],max(temp[1],intervals[i][1])});
             }else{
                 ans.push_back(intervals[i]);
             }
         }
        return ans;
    }
};