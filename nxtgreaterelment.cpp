#include<iostream>
#include<stack>
using namespace std;

int main(){
	int n,a[10],b[10],i;
	cout<<"enter number of elements :";
	cin>>n;
	cout<<"\n enter elements :\n";
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	stack<int>st;
	for(i=n-1;i>=0;i--){
		while(!st.empty()&&st.top()<=a[i])
		st.pop();
		if(st.empty()){
			b[i]=-1;
		}
		else
		   b[i]=st.top();
		st.push(a[i]);
	}
	for(i=0;i<n;i++){
		cout<<"\n "<<b[i]<<" ";
	}
	return 0;
}
