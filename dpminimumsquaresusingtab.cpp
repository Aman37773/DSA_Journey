#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cout<<"enter n: ";
cin>>n;

int iter=pow(n,0.5);
vector<int> dp(n+1,INT_MAX);

dp[0]=0;

for(int i=1;i<=n;i++){
    int iter=pow(i,0.5),get=0;
    for(int j=1;j<=iter;j++){
        get=dp[i-j*j]+1;
        dp[i]=min(dp[i],get);
    }
}

cout<<dp[n];


return 0;
}