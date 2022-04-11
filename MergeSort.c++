#include<iostream>
using namespace std;

void merge(int arr[], int l, int mid, int h){
    int b[h+1];
    int i=0;
    int j=mid+1;
    int k=0;

    while((i<=l) && (j<=h)){
        if(arr[i] < arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }

    for(; i<=l; i++)
        b[k++] = arr[i];

    for(; j<=h; j++)
        b[k++] = arr[j];

    for(int x=0; x<k; x++)
        arr[x] = b[k];
}


void mergeSort(int arr[], int l, int h){
    if(l<h){
        int mid = (l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}


int main(){
    cout<<"Enter size: ";
    int n;
    cin>>n;

    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];

    mergeSort(arr,0,n-1);

    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}