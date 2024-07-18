#include<bits/stdc++.h>
using namespace std;

int main(){
int n,cost[100];
cout<<"enter n: ";
cin>>n;
cout<<"enter cost: ";
for(int i=0;i<=n+1;i++){
    if(i>0&&i<=n){
    cin>>cost[i];
    }
}
cost[0]=0;
cost[n+1]=0;



int prev=cost[0];
int cur=cost[1];

for(int i=2;i<=n+1;i++){
    int save=cur;
    cur=min(prev,cur)+cost[i];
    prev=save;
}

cout<<cur;

return 0;
}
