#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> f(vector<string>&a){
    unordered_map<string,vector<string>>m;
    for(string &s:a){
        string k=s;
        sort(k.begin(),k.end());
        m[k].push_back(s);
    }
    vector<vector<string>>r;
    for(auto &p:m)r.push_back(p.second);
    return r;
}
int main(){
    int n;
    cin>>n;
    vector<string>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<vector<string>>r=f(a);
    for(auto &g:r){
        cout<<"[ ";
        for(string &s:g)cout<<s<<" ";
        cout<<"]\n";
    }
    return 0;
}

