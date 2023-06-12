#include<bits/stdc++.h>
using namespace std;


//Time Complexity -  O(Nlog N)
//Space Complexity -  O(N)
class Solution {
public:
    int merge(vector<int>&nums,int low,int mid,int high){
        int cnt = 0 ;
        int j = mid+1;
        int i =low;
        while(i<=mid && j<=high){
            if(j<=high && (nums[i]>(1ll*2*nums[j]))){
                cnt+=(mid-i+1);
                j++;
            }else{
                i++;
            }
        }
        vector<int>temp;
        int left = low;
        int right  = mid+1;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        int k =0;
        for(int i =low;i<=high;i++){
            nums[i]=temp[k];
            k++;
        }
        return cnt;

    }
    int mergeSort(vector<int>& nums,int low,int high){
        int count  = 0;
        if(low>=high){
            return 0;
        }
        int mid =low+(high-low)/2;
        count+=mergeSort(nums,low,mid);
        count+=mergeSort(nums,mid+1,high);
        count+=merge(nums,low,mid,high);
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        int n =  nums.size();
        return mergeSort(nums,0,n-1);
    }
};