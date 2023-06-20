

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
     void recursion(vector<int> arr,vector<int>& ans,int sum ,int i){
         if(i==arr.size()){
             ans.push_back(sum);
             return;
         }
         
         
        recursion(arr,ans,sum+arr[i],i+1);
         recursion(arr,ans,sum,i+1);
     }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
         vector<int>ans;
         recursion(arr,ans,0,0);
         return ans;
    }
};
