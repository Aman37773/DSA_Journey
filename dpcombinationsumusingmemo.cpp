#include<bits/stdc++.h>
using namespace std;

int solve(int n,int target,int a[],int val,vector<int> &dp){
if(val==target){
return 1;
}
if(val>target){
    return 0;
}

if(dp[val]!=-1){
    return dp[val];
}

int get=0;
    for(int i=0;i<n;i++){
      get = get + solve(n,target,a,val+a[i],dp);
    }
    dp[val]=get;
    return dp[val];
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

vector<int> dp(target+1,-1);

cout<<solve(n,target,a,0,dp);

return 0;
}