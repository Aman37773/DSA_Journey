#include<bits/stdc++.h>
using namespace std;

int solve(int n,int a[],int b[],int i,vector<int> &dp){  //m==1
if(i>=n){
    return 0;
}
if(dp[i]!=-1){
    return dp[i];
}
int get1=INT_MAX,get2=INT_MAX;
    
        if(a[i]<=a[i-1]||b[i]<=b[i-1]||(a[i]>b[i-1]&&b[i]>a[i-1])){
          swap(a[i],b[i]);
           get1 =  solve(n,a,b,i+1,dp)+1;
           swap(a[i],b[i]);
        }
    if(a[i]>a[i-1]&&b[i]>b[i-1]){
        get2=solve(n,a,b,i+1,dp);
    }   

return dp[i]=min(get1,get2);
}


int main(){
int n,a[100],b[100];
cout<<"enter n: ";
cin>>n;
cout<<"enter values of a: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}
cout<<"enter values of b: ";
for(int i=0;i<n;i++){
    cin>>b[i];
}

vector<int> dp(n+1,-1);

cout<<solve(n,a,b,1,dp);


return 0;
}