#include<bits/stdc++.h>
using namespace std;
//Algorithm In O(1) space
//find ans where element occurs more than n/3 times

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         //If we are Finding a Element which is greater Than The n/3 then I am Pretty sure That there is a
         //at max Only 2 elements Not more Than THat


        int el1 =INT_MIN,cnt1=0;
        int el2 = INT_MIN,cnt2=0;


        for(int i =0;i<nums.size();i++){
            if(cnt1 ==0 && el2!=nums[i]){
                el1 =  nums[i];
                cnt1=1;
            }else if(cnt2==0 && el1!=nums[i]){
                 el2 = nums[i];
                 cnt2 =1;
            }else if(el1==nums[i]){
                cnt1++;
            }else if(el2==nums[i]){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }


        cnt1=0;
        cnt2=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==el1){
                cnt1++;
            }
            if(nums[i]==el2){
                cnt2++;
            }
        }

        int mini = ((nums.size())/3)+1;

        vector<int>ans;
        if(cnt1>=mini){
            ans.push_back(el1);
        }
        if(cnt2>=mini){
            ans.push_back(el2);
        }
        return ans;
    }
};