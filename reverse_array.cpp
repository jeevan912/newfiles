#include<iostream>
using namespace std;

void reverse(int a[], int s, int e)
{
	int temp;
	while(s<e) {
		temp=a[s];
		a[s]=a[e];
		a[e]=temp;
		s++;
		e--;
	}
}

void rotate(int a[],int n,int k){
	k=k%n;
	reverse(a,0,n-1);
	reverse(a,0,k-1);
	reverse(a,k,n-1);
}
int main(){
	int k,n,a[10];
	cout<<"enter n value :";
	cin>>n;
	cout<<"\nenter elements :\n";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"\narray is  ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\nenter index to reverse :";
	cin>>k;
	rotate(a,n,k);
	cout<<"\narray is  ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
