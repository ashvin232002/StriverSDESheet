#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>>st;
    int mini ;
    StockSpanner() {
         mini = INT_MAX;
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price,1});
            return st.top().second;
        }else{
            int count  =1;
            while(!st.empty()){
                pair<int,int>v  = st.top();
                if(v.first<=price){
                   count+=v.second;
                   st.pop();
                }else{
                    break;
                }
            }
            st.push({price,count});
            return st.top().second;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */