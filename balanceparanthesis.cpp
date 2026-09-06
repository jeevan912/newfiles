#include<iostream>
#include<stack>
using namespace std;

bool balanced(string s){
	stack<char>st;
	for(int i=0;i<s.length();i++){
		if(s[i]=='{'||s[i]=='['||s[i]=='('){
			st.push(s[i]);
		}
		else if(s[i]=='}'||s[i]==']'||s[i]==')'){
			if(st.empty()){
				return false;
			}
			char ch=st.top();
			st.pop();
			if((s[i]==')'&&ch!='(')||(s[i]=='}'&&ch!='{')||s[i]==']'&&ch!='['){
				return false;
			}
		}
	}
	return true;
}
int main(){
	string s;
	cout<<"Enter expression :";
	cin>>s;
	if(balanced(s))
	  cout<<s<<"is Balanced Paranthesis";
	else
	  cout<<s<<"is Not Balanced paranthesis";
	return 0;
}
