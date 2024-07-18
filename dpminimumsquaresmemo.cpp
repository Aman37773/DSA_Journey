#include<bits/stdc++.h>
using namespace std;

int solve(int n,int iter,vector<int> &dp){
if(n==0){
    return 0;
}
if(n<0){
    return INT_MAX-1;
}

if(dp[n]!=INT_MAX){
    return dp[n];
}


int val=0,get=0,mini=INT_MAX;
    for(int i=1;i<=iter;i++){

        get= solve(n-i*i,iter,dp)+1;

        dp[n]=min(dp[n],get);
    }
    
    return dp[n];
}

int main(){
int n;
cout<<"enter n: ";
cin>>n;

int iter=pow(n,0.5);
vector<int> dp(n+1,INT_MAX);
cout<<solve(n,iter,dp);

return 0;
}