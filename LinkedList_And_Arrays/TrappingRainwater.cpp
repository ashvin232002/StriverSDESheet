#include<bits/stdc++.h>
using namespace std;


//Broute force 
// try from every index find the left maxi and right maxi and compute the ans 
//TC  = O(n^2);


//Some Optimization 
// 1  .Using Prefix Maximum store the left prefix maxi and store the right prefix maxi
//TC =  O(n)+O(n)+O(n) (Linear =  O(n))
//SC =  O(n)+O(n)

//2  . Using stac to find the left maxi and and find the right maxi
//TC =  O(n)+O(n)+O(n) (Linear =  O(n))
//SC =  O(n)+O(n)

//final Optimization
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2)
            return 0;
        
        int maxLeft = height[0];
        int maxRight = height[n-1];
        int ans =0;
        
        int left = 1;
        int right = n-2;
    
            while(left<=right){
                if(maxLeft<maxRight){
                    if(height[left]>=maxLeft)
                        maxLeft = height[left];
                    else
                        ans +=maxLeft- height[left];
                    left++;
                }  else{
                    if(height[right]>=maxRight){
                        maxRight = height[right];
                    }else{
                        ans+=maxRight-height[right];
                    }
                    right--;
                }
            }
        return ans;
    }
};