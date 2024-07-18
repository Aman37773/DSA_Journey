#include<bits/stdc++.h>
using namespace std;

int solve(int n,int a[],int m,int val,vector<int> &dp){
if(m+1==n){
    return 0;
}
int get=0;
if(dp[m]!=0){
    return dp[m];
}
for(int i=m+1;i<n;i++){
    if(a[i]>val){
     get = solve(n,a,i,a[i],dp)+1;
     dp[m]=max(dp[m],get);           //here not used dp[val] because 12 13 12 14 here both 12 have different number of subsequences so thats why taken with respect to index
    }
}
return dp[m];
}


int main(){
int n,a[100];
cout<<"enter n: ";
cin>>n;
cout<<"enter values: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}
int maxy=0;
vector<int> dp(n+1,0);
for(int i=0;i<n;i++){
maxy=max(maxy,solve(n,a,i,a[i],dp)+1);
}
cout<<maxy;
return 0;
}