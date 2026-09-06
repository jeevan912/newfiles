#include<iostream>
using namespace std;

int singlenumber(int a[],int n)
{
	int r=0;
	for(int i=0;i<n;i++){
		r=r^a[i];
		
	}
	return r;
}

int main(){
	int n,a[10];
	cout<<"enter n value :";
	cin>>n;
	cout<<"\nenter elements :\n";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"\nSingle Number is :"<<singlenumber(a,n);
}
