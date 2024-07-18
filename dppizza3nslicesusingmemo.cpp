#include<bits/stdc++.h>
using namespace std;


int solve(int n,int a[],int m,int count,int net,vector<vector<int>> &dp){
if(count==net/3||m>=n){
    return 0;
}
if(dp[m][count]!=-1){
    return dp[m][count];
}
int get=0,maxy=0;
for(int i=m;i<n;i++){
    
get=a[i]+solve(n,a,i+2,count+1,net,dp);
maxy=max(maxy,get);
    
}
return dp[m][count]=maxy;
}


int main(){
int n,a[100];  //multiple of 3
cout<<"enter n: ";
cin>>n;
cout<<"enter slice values: ";
for(int i=0;i<n;i++){
cin>>a[i];
}

vector<vector<int>> dp1(n+1,vector<int>(n+1,-1));
vector<vector<int>> dp2(n+1,vector<int>(n+1,-1));
int get1=solve(n-1,a,0,0,n,dp1);
int get2=solve(n,a,1,0,n,dp2);

cout<<max(get1,get2);
return 0;
}