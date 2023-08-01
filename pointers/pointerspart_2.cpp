#include<bits/stdc++.h>
using namespace std;

//How Pointer works with the arrays and all those stuff.

int main(){


     /*int arr[10] = {2,5,6,52,54};

     cout<<"Printing the address of the first memory block is "<<arr<<endl;
     cout<<arr[0]<<endl;
     cout<<"address of first memory block is  "<<&arr[0]<<endl;
     cout<<"address of the seconf memory block is"<<&arr[1]<<endl;

     cout<<"Printing the *arr is = "<<*arr<<endl;
     cout<<"Printing the *arr is = "<<*arr+1<<endl;
     cout<<"Printing the *(arr+1) = "<<*(arr+1)<<endl; // basically it will be the value of the 1 st location
     cout<<"Printing the *(arr+2) = "<<*(arr+2)<<endl; //basically it simply means that second location

     
     int i =3;
     cout<<i[arr]<<endl;
     */


    /*
        int temp[10] =  {1,2};
        cout<<sizeof(temp)<<endl;
        cout<<sizeof(*temp)<<endl;
        cout<<sizeof(&temp)<<endl;

        int *ptr  =  &temp[0];
        cout<<sizeof(ptr)<<endl;
        cout<<sizeof(*ptr)<<endl;
        cout<<sizeof(&ptr)<<endl;
    */

    /*
        //The address of this 3 would be same as it refers to the only first place of the reference
        int a[20] =  {1,2,3,5};
        cout<<&a[0]<<endl;
        cout<<"->"<<&a<<endl;
        cout<<a<<endl;

        int *p = &a[0];
        cout<<p<<endl;
        cout<<"->"<<&p<<endl;
        cout<<*p<<endl;
    */

/*
   int arr[10];
   //arr =  arr+1; //This gives error because this can not be assignable.

    //this is possible because we can point the pointer to some other location.
    int *ptr  = &arr[0];
    cout<<ptr<<endl;
    ptr =  ptr+1;
    cout<<ptr<<endl;
*/




    //Dealing with character arrays
    int arr[5] =  {1,2,3,4,5};
    char ch[6] = "abcde";

    cout<<arr<<endl;
    cout<<ch<<endl;

    char *c  =  &ch[0];
    //it will not print the address like a int please note it will print the whole stuff.
    cout<<c<<endl;

    char pp  =  'a';
    char *p = &pp;
    cout<<"->"<<p<<endl;

    return  0;

}