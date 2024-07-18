#include<bits/stdc++.h>
using namespace std;

 int solve(int n,int a[],int target,vector<int> &dp){    /////very simple,just like backtracking but go through all the  responses and finally print
if(target==0){
    return 0;
}

if(dp[target]!=INT_MAX){
    return dp[target];
}

for(int i=0;i<n;i++){
    if(target-a[i]>=0){
int get=solve(n,a,target-a[i],dp);

if(get==INT_MAX){
dp[target]=min(dp[target],get);//////////////////applying condition cause infinity+1=-infinity
}
else{
    dp[target]=min(dp[target],get+1);
}

    }
    
}
return dp[target];
}

int main(){
int n,a[100],target;
cout<<"enter n: ";
cin>>n;
cout<<"enter values: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}
cout<<"enter target: ";
cin>>target;


vector<int>dp(target+1,INT_MAX);

int get=solve(n,a,target,dp);

if(get==INT_MAX){
cout<<-1;
}
else{
    cout<<get;
}

return 0;
}