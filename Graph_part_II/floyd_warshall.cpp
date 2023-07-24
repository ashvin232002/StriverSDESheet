#include<bits/stdc++.h>
using namespace std;


//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&dp){
	    // Code here
	    int n = dp.size();

     for(int i=0; i<n; i++) {

         for(int j=0; j<n; j++) {

             if(dp[i][j] == -1) {

                 dp[i][j] = INT_MAX;

             }

         }

     }

     for (int k=0; k<n; k++) {

         for(int i=0; i<n; i++) {

             for(int j=0; j<n; j++) {

                 if(dp[i][k]!=INT_MAX and dp[k][j]!=INT_MAX)

                     dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);

             }

         }

     }
	}
};