#include<bits/stdc++.h>
using namespace std;
int step(int n,int cost[],int mincost[]){
if(n<=1){
    return cost[n];
}

if(mincost[n]!=-1){
    return mincost[n];
}
mincost[n]=min(step(n-1,cost,mincost),step(n-2,cost,mincost))+cost[n];
return mincost[n];
}



int main(){
int n,dp[100],cost[100],mincost[100];
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