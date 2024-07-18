#include<bits/stdc++.h>
using namespace std;

int main(){
int m,n,a[100][100];
cout<<"enter m,n: ";
cin>>m>>n;
cout<<"enter elements: ";
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>a[i][j];
    }
}
int maxy=0;
vector<vector<int>> dp(m,vector<int>(n,-1));


for(int i=m-1;i>=0;i--){
    int right=0,diagonal=0,bottom=0;
    for(int j=n-1;j>=0;j--){

if(j+1<n){
  right=dp[i][j+1];
}
if(i+1<m&&j+1<n){
  diagonal=dp[i+1][j+1];
}
if(i+1<m){
  bottom=dp[i+1][j];
}

if(a[i][j]==1){

     dp[i][j] = min(right,min(bottom,diagonal))+1;
    maxy=max(maxy,dp[i][j]);
    
}
else{
    dp[i][j]=0;
}

    }
}


cout<<maxy;


return 0;
}