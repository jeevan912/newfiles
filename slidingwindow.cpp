#include<iostream>
#include<deque>
using namespace std;

int main(){
	int n,k,a[10];
	cout<<"enter no elements :";
	cin>>n;
	cout<<"\n enter arrray elements :";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"\nenter window size";
	cin>>k;
	deque<int>dq;
	cout<<"\nMaximum elements are";
	for(int i=0;i<n;i++){
		while(!dq.empty()&&dq.front()<=i-k){
			dq.pop_front();
		}
		while(!dq.empty()&&a[dq.back()]<=a[i]){
			dq.pop_back();
		}
		dq.push_back(i);
		if(i>=k-1){
			cout<<"\n"<<a[dq.front()];
		}
	}
	return 0;
}
