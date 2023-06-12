#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return  0;
        }
        set<int>s;
        for(int i =0;i<nums.size();i++){
            s.insert(nums[i]);
        }

        int maxa = 1;
        for(int i =0;i<nums.size();i++){
             if(s.find(nums[i]-1)!=s.end()){
                 continue;
             }else{
                 int curr = nums[i];
                 int streak =1;
                 while(true){
                     if(s.find(curr+1)!=s.end()){
                         streak++;
                         curr++;
                     }else{
                         break;
                     }
                 }
                 maxa=max(maxa,streak);
             }
        }
        return maxa;
    }
};