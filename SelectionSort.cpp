#include<iostream>
using namespace std;

int minimum(int arr[], int s, int e, int &ctr){
	int min=s;
	for(int i=s; i<=e; i++){
		ctr++;
		if(arr[i] < arr[min]){
			min = i;
		}
	}
	return min;
}

int main(){
	int n;
	cout<<"Enter size of array: ";
	cin>>n;

	cout<<"Enter array elements: ";
	int arr[n];
	int ctr=0;
	int swap=0;
	for(int i=0; i<n; i++)
		cin>>arr[i];

	int start = 0, end = n-1;
	while(start<end){
		int m = minimum(arr,start,end, ctr);
		//cout<<ctr<<endl;
		if(start != m){
			int temp = arr[start];
			arr[start] = arr[m];
			arr[m] = temp;
			swap += 2;
		}
		start++;
	}

	cout<<"Sorted array: ";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	cout<<"Number of comparision: "<<ctr<<endl;
	cout<<"Number of swap operation: "<<swap<<endl;
}
