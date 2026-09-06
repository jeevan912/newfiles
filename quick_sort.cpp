#include<iostream>
using namespace std;

int partition(int a[],int l,int h){
	int pivot=a[l];
	int i=l,j=h,temp;
	while(i<j){
		while(a[i]<=pivot&&i<h)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[l];
	a[l]=a[j];
	a[j]=temp;
	return j;
}

void quicksort(int a[],int l,int h){
	if(l<h){
		int p=partition(a,l,h);
		quicksort(a,l,p-1);
		quicksort(a,p+1,h);
	}
}

int main(){
	int n,a[100];
	cout<<"enter number of elements\n";
	cin>>n;
	cout<<"enter elements\n";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	cout<<"sorted array: ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
