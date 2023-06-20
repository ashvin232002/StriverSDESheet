
#include<bits/stdc++.h>
using namespace std;
struct Item{
    int value;
    int weight;
};



class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(Item a ,Item b){
        double first  =  (double)a.value/(double)a.weight;
        double second  =  (double)b.value/(double)b.weight;
        
        return first>second;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        double ans  = 0;
        for(int i =0;i<n;i++){
            if(W-arr[i].weight >=0){
                ans+=arr[i].value;
                W-=arr[i].weight;
            }else{
                ans=ans+(((double)(arr[i].value)*(W))/(double)arr[i].weight);
                break;
            }
        }
        return ans;
    }
        
};