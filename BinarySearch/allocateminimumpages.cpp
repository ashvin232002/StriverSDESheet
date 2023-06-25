#include<bits/stdc++.h>
using namespace  std;


class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int a[],int val ,int m,int n){
        int currsum =0;
        int count =1;
        
        for(int i =0;i<n;i++){
            if(currsum+a[i]<=val){
                currsum+=a[i];
            }else{
                count++;
                if(count>m || a[i]>val){
                    return false;
                }
                currsum = a[i];
            }
        }
        return true;
    }
    int findPages(int a[], int n, int m) 
    {
        //code here
        if(n<m){
            return -1;
        }
        int low  = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        int high  = sum;
        int ans  =-1;
        
       while(low<=high){
           int mid  =  low+(high-low)/2;
           if(isPossible(a,mid,m,n)){
               ans=mid;
               high = mid-1;
           }else{
               low =mid+1;
           }
          
       }
       return ans;
    }
};