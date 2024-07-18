#include<bits/stdc++.h>
using namespace std;





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



for(int i=0;i<n;i++){
    int inc=v[i],ex=0;
    for(int j=limit;j<=0;j--){

        if(i-1>=0&&j-w[i]>=0){
       inc=v[i]+dp[i-1][j-w[i]]; 
        }
        if(i-1>=0){
       ex=dp[i-1][j];
        }
       dp[i][j]=max(inc,ex);
    }
}

cout<<dp[n-1][0];

return 0;
}

/////////solve it