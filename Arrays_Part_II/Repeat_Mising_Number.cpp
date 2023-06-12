#include<bits/stdc++.h>
using namespace  std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow  =  nums[0];
        int fast = nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        int repeated =  slow;

        //for to find the repeated Number 
        //sum = first take the sum of all numbers - repeated number
        //now ((n(n+1))/2)-sum is our ans
    }
};