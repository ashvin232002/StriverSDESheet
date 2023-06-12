#include<bits/stdc++.h>
using namespace std;
//Algorithm In O(1) space

//Element That Occurs More Than N/2 times
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int fre  = 1;
        int prevMaxi = nums[0];
        
        for(int i =1;i<nums.size();i++){
            if(nums[i]==prevMaxi){
                 fre++;
            }else if(fre>0){
                 fre--;
            }else if(fre==0){
                prevMaxi=nums[i];
                fre=1;
            }
        }
        return prevMaxi;
    }
};