#include<bits/stdc++.h>
using namespace std;

int solve(int n,int a[],int i,int j,vector<vector<int>> &dp){

if(i+1==j){
    return 0;
}
if(dp[i][j]!=INT_MAX){
    return dp[i][j];
}
for(int k=i+1;k<j;k++){
int get=a[i]*a[k]*a[j] + solve(n,a,i,k,dp) + solve(n,a,k,j,dp);
dp[i][j]=min(dp[i][j],get);
}
return dp[i][j];
}

int main(){
int n,a[100];
cout<<"enter n: ";
cin>>n;
cout<<"enter values of vertex: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}
vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
cout<<solve(n,a,0,n-1,dp);
return 0;
}