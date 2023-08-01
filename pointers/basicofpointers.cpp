#include<bits/stdc++.h>
using namespace std;

int main(){
    // int num = 5;

    // cout<<"Printing The Number"<<num<<endl;

    // cout<<"Address of num is "<<&num<<endl;

    // int *ptr  =  &num;

    // cout<<" Value is : "<<*ptr<<endl;
    // cout<<" Value is : "<<ptr<<endl;

    // double d  =  4.3;
    // double *p2  = &d;


    // cout<<"Address is "<<&d<<endl;
    // cout<<"Address is :"<<p2<<endl;
    // cout<<"Value is : "<<*p2<<endl;


    // cout<<" Size of Interger is "<<sizeof(num)<<endl;
    // cout<<" size of pointer is "<<sizeof(ptr)<<endl;
    // cout<<"size of p2 is"<<sizeof(p2)<<endl;


/*
//This a re the two technique to initialize with pointer 
//as the two methods are same they are pointing to the same location
    int i = 5;
    int *q  = &i;

    cout<<q<<endl;
    cout<<*q<<endl;

    int *p =  0;
    p = &i;

    cout<<p<<endl;
    cout<<*p<<endl;
*/


   int num =5;
   cout<<"curr num"<<num<<endl;
   int a =  num;
   a++;
   cout<<"before num"<<num<<endl;//no increment in num because the copy would be generated 

   int *p =  &num;
   (*p)++;
   cout<<"after num"<<num<<endl;//increment because the increment at the location point


   //copying a pointer 
   int *q = p;
   cout<<p<<" - "<<q<<endl; //address would be same because two pointer point the same location
   cout<<*p<<" - "<<*q<<endl;

   int i = 3;
   int *t =  &i;

   cout<<(*t)<<endl;
   cout<<((*t)++)<<endl;
   cout<<(*t)<<endl;
   
   cout<<"Printing address of t"<<t<<endl;
   cout<<"size of t"<<sizeof(t)<<endl;
   t =  t +1;
   cout<<"Printing address of t now"<<t<<endl;
}