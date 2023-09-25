#include<bits/stdc++.h>
using namespace std;



int position(vector<int>& a,int low,int high){
    int val = a[low];
    int count = 0;
    for(int i =low+1;i<=high;i++){
        if(a[i]<=val){
            count++;
        }
    }
    
    int pivotIndex =  low+count;
    swap(a[low],a[pivotIndex]);
    
    int i = low;
    int j = high;
    while(i<pivotIndex && j>pivotIndex){
        while(a[i]<a[pivotIndex]){
            i++;
        }
        while(a[j]>a[pivotIndex]){
            j--;
        }
        swap(a[i],a[j]);
        i++;
        j--;
    }
    return pivotIndex;
}
void quickSort(int low,int high,vector<int>&a){

    if(low>=high){
        return;
    }

    int pos = position(a,low,high);
    quickSort(low,pos-1,a);
    quickSort(pos+1,high,a);
}
int main(){

    int n ;
    cin>>n;

    vector<int>a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    quickSort(0,n-1,a);
    for(int  i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;

}