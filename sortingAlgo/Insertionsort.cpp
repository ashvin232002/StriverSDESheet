#include<bits/stdc++.h>
using namespace  std;


void solve(){
    int n ;
    cin>>n;

    vector<int>a(n);
    for(int  i = 0;i<n;i++){
        cin>>a[i];
    }

    for(int i = 1;i<n;i++){
          int j =i-1;
          int val = a[i];
          bool flag =  false;
          while(j>=0){
              if(a[j]>val){
                a[j+1]=a[j];
                j--;
              }else{
                flag = true;
                a[j+1]=val;
                break;
              }
          }
          if(!flag){
            a[0]=val;
          }
    }

    for(int i = 0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;



}
int main(){
    
    solve();

    return  0 ;
}