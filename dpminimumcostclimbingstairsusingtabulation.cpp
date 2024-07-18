#include<bits/stdc++.h>
using namespace std;
int step(int n,int cost[],int mincost[]){
mincost[0]=cost[0];
mincost[1]=cost[1];

for(int i=2;i<=n;i++){
    mincost[i]=min(mincost[i-1],mincost[i-2])+cost[i];
}
return mincost[n];
}



int main(){
int n,cost[100],mincost[100];
cout<<"enter n: ";
cin>>n;
cout<<"enter cost: ";
for(int i=0;i<=n+1;i++){
    mincost[i]=-1;
    if(i>0&&i<=n){
    cin>>cost[i];
    }
}
cost[0]=0;
cost[n+1]=0;
cout<<step(n+1,cost,mincost);


return 0;
}