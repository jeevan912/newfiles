#include<iostream>
using namespace std;

struct Item{
float w,p,v;
};


void knapsack(Item item[],int n,float M){
  float x[n];
  for(int i=0;i<n;i++){
         x[i]=0;
          item[i].v=item[i].p/item[i].w;
  }
  float weight=0;
  while(weight<M){
    int i=-1;
    for(int j=0;j<n;j++){
      if(x[j]<1){
       if(i==-1||item[j].v>item[i].v)
          i=j;
      }
    }
    if(weight+item[i].w<=M){
      x[i]=1;
      weight=weight+item[i].w;
    }
    else{
      x[i]=(M-weight)/item[i].w;
      weight=M;
    }
  }
  float totalProfit=0;
  for(int i=0;i<n;i++)
   totalProfit=totalProfit+x[i]*item[i].p;
  cout<<"Selected fractions:\n";
  for(int i=0;i<n;i++)
    cout<<"x["<<i+1<<"]="<<x[i]<<endl;
  cout<<"Maximum Profit="<<totalProfit<<endl;
}
int main(){
 int n;
 float M;
 cout<<"Enter number of items: ";
 cin>>n;
 Item item[n];
 cout<<"Enter weight and profit:\n";
 for(int i=0;i<n;i++)
   cin>>item[i].w>>item[i].p;
 cout<<"Enter knapsack capacity: ";
 cin>>M;
 knapsack(item,n,M);
 return 0;
}