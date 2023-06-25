#include<bits/stdc++.h>
using namespace  std;


//TC o(logn);
//SC O(1)

class Solution {
    int PivotElement(vector<int>& nums){
        int low = 0;
        int high = nums.size()-1;
        int mid = low +(high-low)/2;
        
        while(low<high){
            if(nums[mid]>=nums[0]){
                low = mid+1;
            }else{
                high = mid;
            }
            mid = low +(high-low)/2;
        }
        return low;
    }
    int binarySearch(vector<int>& nums, int target,int low ,int high){
        int mid = low +(high-low)/2;
        
        while(low<=high){
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
             mid = low +(high-low)/2;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = PivotElement(nums);
        if(nums[pivot]==target){
            return pivot;
        }
        else if(target>nums[pivot]&& target<=nums[n-1]){
            return binarySearch(nums,target,pivot,n-1);
        }else{
            return binarySearch(nums,target,0,pivot-1);
        }
        return -1;
    }
};