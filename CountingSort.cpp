#include<iostream>
using namespace std;

void countingSort(int arr[], int n){
    int max = arr[0];

    for(int i=1; i<n; i++)
        if(arr[i] > max)
            max=arr[i];

    int count[max+1]={0};

    for(int i=0; i<n; i++)
        count[arr[i]]++;

    for(int i=1; i<=max; i++)
        count[i] = count[i] + count[i-1];
    
    int b[n];
    for(int i=0; i<n; i++)
        b[--count[arr[i]]] = arr[i];

    for(int i=0; i<n; i++)
        arr[i] = b[i];
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

    countingSort(arr,n);
    display(arr,n);

    return 0;
}