#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void addAns(vector<vector<string>>& board,vector<vector<string>>& ans,int n){
        vector<string>curr;
        for(int i =0;i<n;i++){
            string temp ="";
            for(int j = 0;j<n;j++){
                temp+=(board[i][j]);
            }
            curr.push_back(temp);
        }
        ans.push_back(curr);
    }
    bool isSafe(int row,int col,vector<vector<string>>& board,int n){
        int x  = row;
        int y = col;

        while(y>=0){
            if(board[row][y]=="Q"){
                return false;
            }
            y--;
        }

        y=col;
        x=row;
        while(x<n && y>=0){
            if(board[x][y]=="Q"){
                return false;
            }
            x++;
            y--;
        }

        x=row;
        y=col;
        while(x>=0 && y>=0){
            if(board[x][y]=="Q"){
                return false;
            }
            x--;
            y--;
        }
        return true;
    }
    void recursion(int col ,vector<vector<string>>& board,vector<vector<string>>& ans,int n){
        if(col==n){
            addAns(board,ans,n);
            return;
        }

        for(int row = 0;row<n;row++){
             if(isSafe(row,col,board,n)){
                   board[row][col]="Q";
                   recursion(col+1,board,ans,n);
                   board[row][col]=".";
             }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<string>>board(n,vector<string>(n,"."));
        recursion(0,board,ans,n);
        return ans;
    }
};