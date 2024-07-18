#include<bits/stdc++.h>
using namespace std;


int solve(int n,int v[],int w[],int weight,int &limit,vector<vector<int>> &dp){
    if(weight>limit){
    return INT_MIN;
}
if(n<0){
    return 0;
}

if(dp[n][weight]!=-1){
    return dp[n][weight];
}

    int inc=v[n]+solve(n-1,v,w,weight+w[n],limit,dp);
    int ex=solve(n-1,v,w,weight,limit,dp);
    
    dp[n][weight]=max(inc,ex);
    return dp[n][weight];
}


int main(){
int n,v[100],w[100],limit;

cout<<"enter n: ";
cin>>n;
cout<<"enter values: ";
for(int i=0;i<n;i++){
    cin>>v[i];
}
cout<<"enter weight: ";
for(int i=0;i<n;i++){
    cin>>w[i];
}
cout<<"enter limit: ";
cin>>limit;

vector<vector<int>> dp(n,vector<int>(limit+1,-1));

cout<<solve(n-1,v,w,0,limit,dp);




return 0;
}