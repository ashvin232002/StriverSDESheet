#include<bits/stdc++.h>
using namespace std;


int main(){

//     int i = 5;

//     int *p =  &i;
//     int **p2 = &p;

//    cout<<" printing p "<<p<<endl;
//    cout<<" address of p "<<&p<<endl;

/*
   //This three output would be same
   cout<<i<<endl;
   cout<<*p<<endl;
   cout<<**p2<<endl;

*/

/*
   //this three output also would be same.
   cout<<&i<<endl;
   cout<<p<<endl;
   cout<<*p2<<endl;
*/






     //MCW type
     /*int first  =  8;
     int second = 18;
     int *ptr =  &second;
     *ptr =  9;
     cout<<first<<" "<<second<<endl;
     */

     /*
     int first  =  6;
     int *p = &first;
     int *q =  p;
     (*q)++;
     cout<<first<<endl;
     */

     /*
     int first  =  8;
     int *p = &first;
     cout<<(*p)++<<" ";
     cout<<first<<endl;
     */

     /*
     int *p = 0;
     int first  =  110;
     p =  &first;
     cout<< *p <<endl;
     */

    /*
     int first  =  8;
     int second  = 11;
     int *third  =  &second;
     first =  *third;
     *third =  *third + 2;
     cout<<first<<" "<<second<<endl;
     */


    /*
    float f  =  12.5;
    float p =  21.5;

    float* ptr  = &f;

    (*ptr)++;
    *ptr  =  p;
    cout<<*ptr<<" "<<f<<" "<<p<<endl;
    */

   
   /*
    int arr[5];
    int *ptr ;
    cout<<sizeof(arr)<<" "<<sizeof(ptr)<<endl;
    */

   /*

   int arr[] =  {11,21,13,14};
   cout<<*(arr)<<" "<<*(arr+1)<<endl;
   */

  /*
  int arr[6] = {11,12,13};
  cout<<arr<<" "<<&arr<<endl; 
  */

  /*
  int arr[6] = {11,21,13};
  cout<<arr<<endl;
  cout<<(arr+1)<<endl;
  */


  /*
  int arr[6] = {11,21,31};
  int *p = arr;
  cout<<p[2]<<endl;

  */

  /*
   int arr[] =  {11,12,13,14,15};
   cout<<*(arr)<<" "<<*(arr+3)<<endl;
   */

    /*
    int arr[] = {11,21,31,41};
    int *ptr =  arr++; //In the array this thing is not possible please make note 
    cout<<*ptr<<endl;
    */

    /*
    char ch  =  'a';
    char *ptr =  &ch;
    ch++;
    cout<<*ptr<<endl;
    */

    
    return  0;
}