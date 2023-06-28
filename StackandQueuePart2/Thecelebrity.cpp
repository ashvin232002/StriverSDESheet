#include<bits/stdc++.h>
using namespace std;



//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    bool knows(vector<vector<int>>&M,int a,int b,int n){
        if(M[a][b]==1){
            return true;
        }else{
            return false;
        }
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>s;
        for(int i =0;i<n;i++){
            s.push(i);
        }
        
        while(s.size()>1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(knows(M,a,b,n)){
                s.push(b);
            }else{
                s.push(a);
            }
        }
        int candidate =  s.top();
        int RowCount =0;
        for(int i =0;i<n;i++){
            if(M[candidate][i]==0){
                RowCount++;
            }
        }
        if(RowCount!=n){
            return -1;
        }
        
        int ColCount =0;
        for(int i =0;i<n;i++){
            if(M[i][candidate]==1){
                ColCount++;
            }
        }
        if(ColCount!=n-1)
          return -1;
          
        return candidate;
    }
};