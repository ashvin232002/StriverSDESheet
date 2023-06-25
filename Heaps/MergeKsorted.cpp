

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    void heapify(vector<int>& ans,int n ,int i){
        int largest =  i;
        int left =  2*i+1;
        int right  =  2*i+2;
        
        
        if(left<n && ans[left]>ans[largest]){
            largest = left;
        }
        
        if(right<n && ans[right]>ans[largest]){
            largest =  right;
        }
        
        if(largest != i){
            swap(ans[largest],ans[i]);
            heapify(ans,n,largest);
        }
    }
    void buildHeap(vector<int>& ans,int n){
        for(int i =(n/2 -1);i>=0;i--){
            heapify(ans,n,i);
        }
    }
    void heapSort(vector<int>& ans ,int n){
        buildHeap(ans,ans.size());
        for(int i =n-1;i>=0;i--){
            swap(ans[0],ans[i]);
            heapify(ans,i,0);
        }
        
    }
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int>ans;
        for(int  i = 0;i<K;i++){
            for(int  j=0;j<K;j++){
                ans.push_back(arr[i][j]);
            }
        }
        
        heapSort(ans,ans.size());
        return ans;
    }
};