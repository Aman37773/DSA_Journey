#include<bits/stdc++.h>
using namespace std;

int solve(int n,int i,vector<vector<int>> &dp){  //i==n
if(i==0){
return 1;
}
if(i==1||i==2){
    return i;
}

if(dp[n][i]!=-1){
    return dp[n][i];
}

int get=0,ans=0;

for(int i=n;i>=1;i--){
get=solve(i-1,i-1,dp)*solve(n-i,n-i,dp);
ans=ans+get;
}
    
    return dp[n][i]=ans;
}

int main(){
int n;
cout<<"enter n: ";
cin>>n;
vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
cout<<solve(n,n,dp);

return 0;
}