#include<bits/stdc++.h>
using namespace  std;


//recursive solution
// TC O(n! * n)
class Solution {
public:
   int order;
    void solve(string path,int index,vector<string>&ans){
        if(index>=path.size()){
            order--;
            ans.push_back(path);
            return;
        }
        
        sort(path.begin()+index,path.end());
        for(int i= index;i<path.size();i++){
            swap(path[index],path[i]);
            solve(path,index+1,ans);
            if(order==0) return;
            swap(path[index],path[i]);
        }
    }
    string getPermutation(int n, int k) {
        order=k;

        string path = "";
        for(int i =1;i<=n;i++){
            path += i+'0';
        }
        int index =0;
        vector<string>ans;
        solve(path,0,ans);
        
        return ans[k-1];
    }
};


//TC O(N^N)
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact  = 1;
        vector<int>numbers;
        for(int  i =1;i<n;i++){
            fact =  fact*i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans =  "";
        k = k-1;
        while(true){
            ans =  ans+ to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact);
            if(numbers.size()==0){
                break;
            }
            k = k % fact;
            fact =  fact /numbers.size();
        }
        return ans;
    }
};

