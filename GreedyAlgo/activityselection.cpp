#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        
        vector<pair<int,int>>v;
        for(int i  = 0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b){
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first<b.first;
        });
        int count   = 1;
        int currEnd =  v[0].first;
        
        for(int i =1;i<n;i++){
            if( v[i].first>currEnd && v[i].second>currEnd){
                currEnd =  v[i].first;
                count++;
            }
        }
        return count;
    }
    
};