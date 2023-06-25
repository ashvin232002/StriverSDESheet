#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    bool isValid(int i ,int j,vector<vector<int>>& m ,vector<vector<int>>& visited){
        if(i<0 || j<0 || i>=m.size() || j>=m.size() || m[i][j]==0 || visited[i][j]==1){
            return false;
        }
        return true;
    }
    void recursion(vector<vector<int>>& m,vector<string>& ans,string &curr , vector<vector<int>>&visited,int n,int i,int j){
        if(i==m.size()-1 &&j==m[0].size()-1){
            ans.push_back(curr);
            return;
        }
        visited[i][j]=1;
        if(isValid(i-1,j,m,visited)){
            curr.push_back('U');
            recursion(m,ans,curr,visited,n,i-1,j);
            curr.pop_back();
        }
        if(isValid(i+1,j,m,visited)){
            curr.push_back('D');
            recursion(m,ans,curr,visited,n,i+1,j);
            curr.pop_back();
        }
        
        if(isValid(i,j+1,m,visited)){
            curr.push_back('R');
            recursion(m,ans,curr,visited,n,i,j+1);
            curr.pop_back();
        }
        if(isValid(i,j-1,m,visited)){
            curr.push_back('L');
            recursion(m,ans,curr,visited,n,i,j-1);
            curr.pop_back();
        }
        visited[i][j]=-1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0){
            return {};
        }
        vector<vector<int>>visited(n,vector<int>(n,-1));
        vector<string>ans;
        string curr="";
        recursion(m,ans,curr,visited,n,0,0);
        return ans;
    }
};
