#include<bits/stdc++.h>
using namespace std;


void solve(){
     int n ;
     cin>>n;
     vector<int>a(n);
     for(int i = 0;i<n;i++){
        cin>>a[i];
     }

     for(int i = 0;i<n;i++){
        int mini = INT_MAX;
        int index =-1;
        for(int j =i;j<n;j++){
            if(mini>=a[j]){
                mini = a[j];
                index = j; 
            }
        }
        swap(a[i],a[index]);
     }

     for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
     }
     cout<<endl;



}
int main(){
    solve();

    return  0 ;

}