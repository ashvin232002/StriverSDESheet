#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxRight = prices[n-1] ;
        int profit = 0;
        for(int i = n-2;i>=0;i--){
            
            if(prices[i]>maxRight)
                maxRight = prices[i];
            int diff = -prices[i]+maxRight;
            profit = max(diff,profit);
            
        }
        
        return profit;
    }
};