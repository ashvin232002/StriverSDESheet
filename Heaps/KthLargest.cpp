
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //By Using Priority_Queue(Heap)
        priority_queue<int,vector<int>>pq;
        
        int n = nums.size();
        
        for(int i =0;i<n;i++){
            pq.push(nums[i]);
        }
        
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};