//Heap  : Heap is Complete Binary Tree that comes with a heap Order Property.
//Every Level Filled Except The last level
//Nodes are storing from left to right 


//implementing a heap in the form of  a array 
// Node -> ith index 
//left child ->  2*ith index
//right child -> (2*i +1)th index

#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size ;


    Heap(){
        arr[0]=-1;
        size =0;
    }

    //insertion Time Complexity O(logn)
    void insert(int val ){
       size  = size+1;
       int index  =  size;
       arr[index] =  val;

       while(index>1){
        int parent  =  index/2;
        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            index = parent;
        }else{
            return;
        }
       }
    }

    // Deletion TC : O(logn)
    void deleteFromHeap(){
         if(size==0){
            cout<<"Nothing To delete"<<endl;
            return ;
         }

         //step 1 : put a last element into first index
         arr[1] =  arr[size];

         //step 2 : remove last element
         size--;

         //step 3 : take root node to it's correct Position 
         int i =1;
         while(i<size){
            int leftIndex  =  2*i;
            int rightIndex =  2*(i+1);

            if(leftIndex<=size && arr[leftIndex]>arr[i]){ //parent small child big 
                  swap(arr[i],arr[leftIndex]);
                  i = leftIndex;
            }else if(rightIndex<=size && arr[rightIndex]>arr[i]){//parent small Child big 
                  swap(arr[rightIndex],arr[i]);
                  i = rightIndex;
            }else{
                return;
            }
         }
    }
    void print(){
        for(int i =1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


//for the heapify algorithm
//(n/2 + 1) to  n  nodes are the leaf nodes , so no need to process
// Heapify Algorithm Time Complexity O(logn)


//maxHeap algo
//HW minHeap
void heapify(int arr[] , int n ,int i){
    int largest  =  i;
    int left = 2*i;
    int right  = 2*i +1;

    
    if(left<=n && arr[largest]<arr[left]){ //selected index is smaller than it's left.
        largest =  left;
    }

    if(right<=n && arr[largest]<arr[right]){ //selected index smaller tahn it's right
         largest = right;
    }

    if(largest != i ){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest); //if the further restructuring is possible
    }
}



//Heap Sort
void heapSort(int arr[],int n){
    int size  = n ;
    while(size > 1){
        //step1 : swap 
        swap(arr[size],arr[1]);
        size--;

        //step2 
        heapify(arr,size,1);
    }
}
int main(){

    Heap h;
    h.insert(15);
    h.insert(9);
    h.insert(10);
    h.insert(4);
    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
    // heap creation
    for(int i = n/2 ;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"Printing The final Heapify Array"<<endl;
    for(int i =1;i<=n;i++){
       cout<<arr[i]<<" ";
    }
    cout<<endl;

    //heapSort 
    heapSort(arr,n);
    cout<<"Printing the Final HeapSort array"<<endl;
    for(int i =1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return  0 ;
}