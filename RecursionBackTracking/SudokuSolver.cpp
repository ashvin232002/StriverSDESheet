#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool isSafe(vector<vector<char>>& board,int value,int i ,int j){
        int row  = i;
        int col  = j;
        int n =  board.size();
        for(int col = 0;col<n;col++){
            if(board[i][col]==value+'0'){
                return false;
            }
        }

        for(int  row=0;row<n;row++){
            if(board[row][j]==value+'0'){
                return false;
            }
        }

        //dry run the formula for better understanding 
        //row  =  3*(row/3)+i/3
        //col  =  3*(col/3)+i%3
        for(int  i  = 0;i<board.size();i++)
        {
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==value+'0'){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int  n =  board.size();

        for(int  i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(board[i][j]=='.'){
                    for(int  val = 1;val<=9;val++){
                        if(isSafe(board,val,i,j)){
                            board[i][j]=val+'0';

                            //further solution possible
                            bool solutionPossible =  solve(board);
                            if(solutionPossible){
                                return true;
                            }else{
                                board[i][j]='.';
                            }
                        }
                    }
                    //if i tried all the solution with possible value for that particular point
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};