#include<bits/stdc++.h>
using namespace std;

int solve(int n,int a[],int dp[] ){
    if(n<0){
        return 0;
    }
    if(n==0){
        return a[0];
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int inc=solve(n-2,a,dp)+a[n];
    int ex=solve(n-1,a,dp);     ///////////another version of backtracking
    dp[n]= max(inc,ex);
    return dp[n];
}



int main(){
int n,a[100],dp[100];
cout<<"enter n: ";
cin>>n;
cout<<"enter elements: ";
for(int i=0;i<n;i++){
    cin>>a[i];
    dp[i]=-1;
}
dp[n]=-1;
cout<<solve(n-1,a,dp);



return 0;
}