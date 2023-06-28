#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m){
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        
        int countOne=0;
        queue<pair<int,int>>q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    countOne++;
                }
            }
        }
        
        
         if(q.empty() && countOne>0){
               return -1;
           }
        if(q.empty() && countOne==0){
            return 0;
        }
        
        int count = 0;
        while(!q.empty()){
            int t = q.size();
            
            while(t--){
                int i = q.front().first;
                int j = q.front().second;
            
                if(check(i+1,j,n,m)&&grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }

                if(check(i-1,j,n,m)&&grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }

                if(check(i,j+1,n,m)&&grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }

                if(check(i,j-1,n,m)&&grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }

                q.pop();
            }
            count++;
        }
        
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
       return count-1;
        
        
    }
};