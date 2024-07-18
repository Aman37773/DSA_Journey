#include<bits/stdc++.h>
using namespace std;

int solve(int n,int m,int x,int val,int sum,vector<vector<int>> &dp ){
if(sum==x&&val==n){
    return 1;
}
if(val==n||sum>x||sum==x&&val!=n){
    return 0;
}
if(dp[val][sum]!=-1){
  return dp[val][sum];
}
int get=0;
for(int i=1;i<=m;i++){
  get= get+ solve(n,m,x,val+1,sum+i,dp);
}
return dp[val][sum]=get;
}


int main(){
int m,n,x;
cout<<"enter m,n,x: "; //m->faces  n->dice  x->target
cin>>m>>n>>x;
vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
cout<<solve(n,m,x,0,0,dp);

return 0;
}