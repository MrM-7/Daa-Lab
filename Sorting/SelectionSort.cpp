#include<iostream>
using namespace std;

void swap(int arr[], int i1, int i2){
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

void selectionSort(int arr[], int n, int &cmp, int &swp){

    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            cmp++;
            if(arr[j] < arr[min])
                min = j;
        }
        if(min != i){
            swp = swp + 2;
            swap(arr,min,i);
        }
    }

}

void display(int arr[], int n){
    cout<<"Sorted Array: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main(){
    cout<<"Enter size: ";
    int n;
    cin>>n;

    cout<<"Enter array elements: ";
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int cmp = 0; // To count No. of comparision
    int swp = 0; // To count No. of swap

    selectionSort(arr,n, cmp, swp);
    display(arr,n);
    
    cout<<"\nNumber of comparision: "<<cmp<<endl;
    cout<<"Number of swap operation: "<<swp<<endl;

    return 0;
}
