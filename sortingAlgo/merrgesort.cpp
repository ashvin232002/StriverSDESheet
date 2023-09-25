#include<bits/stdc++.h>
using namespace std;


void merge(int low,int high,vector<int>& a){
    int mid  = low+(high-low)/2;
    vector<int>v(high-low+1);

    int i =low;
    int j = mid+1;
    int k =0;

    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            v[k]=a[i];
            i++;
            k++;
        }else{
            v[k]=a[j];
            k++;
            j++;
        }
    }

    while(i<=mid){
        v[k]=a[i];
        i++;
        k++;
    }
    while(j<=high){
        v[k]=a[j];
        j++;
        k++;
    }
    
     k =0;
    for(int i=low;i<=high;i++){
        a[i]=v[k];
        k++;
    }

}
void mergeSort(int low,int high,vector<int>&a){
    if(low>=high){
        return;
    }
    int mid  =  low+(high-low)/2; 
    mergeSort(low,mid,a);
    mergeSort(mid+1,high,a);
    merge(low,high,a);
}
int main(){
    int n ;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }

    mergeSort(0,n-1,a);

    for(int  i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}