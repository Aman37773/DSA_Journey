#include<bits/stdc++.h>
using namespace std;

int solve(int n,int a[],int dp[] ){
    
        dp[0]= a[0];
    dp[-1]=0;
   for(int i=1;i<=n;i++){
    int inc=dp[i-2]+a[i];
    int ex=dp[i-1];     ///////////another version of backtracking
    dp[i]= max(inc,ex);
   }
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