
#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i =0;
        int j =0;
        int n = nums.size();
        int  ans  =  INT_MIN;
        while(j<n){
            if(nums[j]==1){
                 j++;
            }else{
                ans=max(ans,j-i);
                j++;
                i=j;
            }
        }
        ans=max(ans,j-i);
        return ans;
    }
};
