#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int countPos  = 0 ;
        int zero =0;
        int ans  = 0;
        int currsum = 0 ;
        int mini =INT_MIN;
        for(int i =0;i<nums.size();i++){
            currsum+=nums[i];
            mini=max(mini,nums[i]);
            if(nums[i]>0){
                countPos++;
            }
            if(nums[i]==0){
                zero++;
            }
            if(currsum<0){
                currsum=0;
                continue;
            }
            ans=max(ans,currsum);
        }


        if(countPos==0 && zero==0){
            return mini;
        }else if(countPos == 0 ){
            return 0;
        }
        return ans;
    }
};