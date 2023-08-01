#include<bits/stdc++.h>
using namespace std;

void print(int *p){
    cout<<*p<<endl;
}


void update(int *p){
    p = p+1;
    cout<<"   inside "<<p<<endl;

    *p = *p + 1;
}


int getSum(int arr[],int n){
    //when we pass the array it will not pass the array but it will pass
    //the pointer actually not the actual array .
    cout<<"Printing the size of arr :"<<sizeof(arr)<<endl;

    int sum = 0;
    for(int i =0;i<n;i++){
        sum+=arr[i];
        // cout<<arr[i]<<endl;
        // sum+=i[arr]; do remember this would be also same 
    }
    return sum;
}


int main(){
   int value  =  5;
   int *p =  &value;

   print(p);
   cout<<"   BEFORE "<<p<<endl;
   cout<<"   BEFORE "<<(*p)<<endl;
   update(p);
   cout<<"   AFTER  "<<p<<endl;
   cout<<"   AFTER  "<<(*p)<<endl;


   

   int arr[6] = {1,2,3,4,5,8};
   cout<<"Sum is "<<getSum(arr,6)<<endl;
   cout<<"Sum is "<<getSum(arr+3,3)<<endl;


   return  0;

}