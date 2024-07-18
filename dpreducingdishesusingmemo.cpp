#include<bits/stdc++.h>
using namespace std;
int solve(int n,int a[],int iter,int p,vector<vector<int>> &dp){  //iter=0,p=1
if(iter==n){
    return 0;
}

if(dp[iter][p]!=INT_MIN){
    return dp[iter][p];
}

int inc=a[iter]*p + solve(n,a,iter+1,p+1,dp);
int ex=solve(n,a,iter+1,p,dp);

dp[iter][p]=max(inc,ex);
return dp[iter][p];
}

int main(){
int n,a[100];
cout<<"enter n: ";
cin>>n;
cout<<"enter satisfaction numbers: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a,a+n);
vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MIN));
cout<<solve(n,a,0,1,dp);
return 0;
}