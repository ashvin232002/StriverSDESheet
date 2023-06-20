#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int i =1;
    	int j =0;
    	int needed_platform =1;
    	int max_needed_platform =1;
    	
    	while(i<n && j<n){
    	    if(arr[i]>dep[j]){
    	        needed_platform--;
    	        j++;
    	    }else{
    	        needed_platform++;
    	        i++;
    	    }
    	    max_needed_platform = max(max_needed_platform,needed_platform);
    	}
    	return max_needed_platform;
    }
};
