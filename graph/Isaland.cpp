#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recursion(vector<vector<char>>&grid,int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0'){
            return ;
        }

        grid[i][j]='0';
        recursion(grid,i+1,j,n,m);
        recursion(grid,i-1,j,n,m);
        recursion(grid,i,j+1,n,m);
        recursion(grid,i,j-1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]=='1'){
                    recursion(grid,i,j,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};

