#include<bits/stdc++.h>
using namespace std;

int solve(int n,int x,int y,int z,int dp[]){
if(n<0){
    return INT_MIN;
}
if(n==0){
    return 0;
}
if(dp[n]!=-1){
return dp[n];
}
    int get1=solve(n-x,x,y,z,dp);
    int get2=solve(n-y,x,y,z,dp);
    int get3=solve(n-z,x,y,z,dp);
    dp[n]= max(max(get1,get2),get3)+1;
    return dp[n];
}



int main(){
int n,dp[100];
cout<<"ener n: ";
cin>>n;
int x,y,z;
cout<<"enter x,y,z: ";
cin>>x>>y>>z;
for(int i=0;i<=n;i++){
    dp[i]=-1;
}

cout<<solve(n,x,y,z,dp);
return 0;
}