#include<iostream>
using namespace std;

int main()
{
	int n,sum=0,i,a[10];
	cout<<"enter n value :";
	cin>>n;
	cout<<"\nenter elements :\n";
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		sum=sum+a[i];
	}
	cout<<"\nSum of array elements :"<<sum;
	return 0;
}
