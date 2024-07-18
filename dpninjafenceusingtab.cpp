#include <bits/stdc++.h> 
using namespace std;



int main(){
    int n,k;   //n->fence  k->colour
    cout<<"enter n: ";
cin>>n;
cout<<"enter k: ";
cin>>k;
vector<long long int> dp(n+1,-1);
 


dp[0]=k;
dp[1]=k;
for(int i=2;i<=n;i++){
    if(i-3>=0){
dp[i]=(dp[i-1]*k - dp[i-3] + 1000000007)%1000000007;
    }
    else{
        dp[i]=(dp[i-1]*k + 1000000007)%1000000007;
    }
}

cout<<(dp[n]+1000000007)%1000000007;

    return 0;
}

