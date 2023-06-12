#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int start = 0;
        int end =  n*m-1;

        while(start<=end){
            int mid  =  start+(end-start)/2;
            int row,col;
            row=mid/m;
            col =  mid%m;
            // cout<<mid<<" "<<row<<col<<endl;
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col]>target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return false;
    }
};