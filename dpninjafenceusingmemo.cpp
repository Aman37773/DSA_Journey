#include <bits/stdc++.h> 
using namespace std;
long long int solve(int n,int k,vector<int> &dp){

if(n<0){
    return 0;
}
if(n==1||n==0){
    return k;
}

if(dp[n]!=-1){
    return dp[n];
}


dp[n]=(solve(n-1,k,dp)*k-solve(n-3,k,dp)+1000000007)%1000000007;
return dp[n];
}


int main(){
    int n,k;   //n->fence  k->colour
    cout<<"enter n: ";
cin>>n;
cout<<"enter k: ";
cin>>k;
vector<int> dp(n+1,-1);
 long long int get= (solve(n,k,dp)+1000000007)%1000000007;
    cout<<get;
    return 0;
}

