#include<bits/stdc++.h>
using namespace std;

int solve(int m,int n,int a[100][100],int p,int q,int &maxy,vector<vector<int>> &dp){

if(p==m||q==n){
    return 0;
}

if(dp[p][q]!=-1){
    return dp[p][q];
}

int right=solve(m,n,a,p,q+1,maxy,dp);
int diagonal=solve(m,n,a,p+1,q+1,maxy,dp);
int bottom=solve(m,n,a,p+1,q,maxy,dp);

if(a[p][q]==1){

     dp[p][q] = min(right,min(bottom,diagonal))+1;
    maxy=max(maxy,dp[p][q]);
    return dp[p][q];
}
else{
    return dp[p][q]=0;
}

}


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
solve(m,n,a,0,0,maxy,dp);

cout<<maxy;


return 0;
}