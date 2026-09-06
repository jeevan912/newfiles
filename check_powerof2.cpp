#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"enter number :";
	cin>>n;
	if(n>0&&(n&(n-1))==0){
		cout<<"\nThe given number "<<n<<" is a power of 2";
	}
	else
	cout<<"\nThe given number "<<n<<" is not a power of 2";
	return 0;
}
