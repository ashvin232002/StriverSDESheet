#include<bits/stdc++.h>
using namespace  std;

int merge(vector<int>& arr,int low,int mid,int high){
    vector<int>temp ; //taking the TEMPORARY Array
    int left =  low;
    int right  =  mid+1;
    int cnt = 0;
    while(left<=mid && right<=high){
        if(arr[left] <=arr[high]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return cnt; 
}


int mergeSort(vector<int>& arr,int low,int high){
    int cnt = 0;
    if(low>=high)return cnt;
    int mid  =  (low+high)/2;
    cnt+=mergeSort(arr,low,mid);
    cnt+=mergeSort(arr,mid+1,high);
    cnt+=merge(arr,low,mid,high);
    return cnt;
}


int numberOfInversions(vector<int>& a,int n){
     return mergeSort(a,0,n-1);
}


int main(){
    vector<int>a  =  {5,4,3,2,1};
    int n =  5;
    int count  =  numberOfInversions(a,n);
    cout<<"The Number of The Inversions are :"<<count<<endl;
    return 0 ;
}
