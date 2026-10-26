#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;
vector<int> twosum(vector<int> &arr,int target){
	unordered_map<int,int>map;
	for(int i=0;i < arr.size,i++){
		int complement = target - arr[i];
		if(map.find(complement) != map.end()){
			return {map[complement],i};
		}
		map[arr[i]] = i;
	} 
	return {};
}
int main (){
	int n;
	cout<<"Enter the  number of elements :";
	cin>>n;
	vector<int> arr(n);
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
	int target;
	count<<"enter the target:";
	cin>>target;
	vector<int> result = twosum(arr,target);
	if(!result.empty()){
		cout<<"indecies:" <<result[0] << ","<<result[1] << endl
	
	}
	return 0;
}
