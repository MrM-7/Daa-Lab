#include<iostream>
using namespace std;

void swap(int arr[], int i1, int i2){
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

void heapify(int arr[], int n, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;

    if(l<n && arr[l]>arr[largest])
        largest=l;

    if(r<n && arr[r]>arr[largest])
        largest = r;

    if(largest != i){
        swap(arr,largest,i);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){

    //Building Heap
    for(int i=n/2-1; i>=0; i--)
        heapify(arr,n,i);

    //Deleting Heap
    for(int i=n-1; i>0; i--){
        swap(arr,i,0);
        heapify(arr,i,0);
    }
}

void display(int arr[], int n){
    cout<<"Sorted elements: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main(){
    int n; 
    cout<<"Enter size: ";
    cin>>n;

    int arr[n];
    cout<<"Enter Elements: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];

    heapSort(arr,n);
    display(arr,n);

    return 0;
}