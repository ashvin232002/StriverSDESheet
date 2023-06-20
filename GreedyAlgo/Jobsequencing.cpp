
#include<bits/stdc++.h>
using namespace std;
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};


class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
   
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int,int>>v;
        for(int i =0;i<n;i++){
            v.push_back({arr[i].profit, arr[i].dead});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        int max_dead_line = 0;
        for(int i =0;i<v.size();i++){
            max_dead_line = max(max_dead_line,v[i].second);
        }
        
        vector<int>deadline(max_dead_line+1,-1);
        int count = 0;
        int maxProfit =0;
        
        for(int i =0;i<n;i++){
           int j  = v[i].second;
           
           while(j>=1 && deadline[j]!=-1){
               j--;
           }
           if(j<1){
               continue;
           }else{
               maxProfit+=v[i].first;
               count++;
               deadline[j]=i;
           }
            
        }
        
        return {count,maxProfit};
    } 
};