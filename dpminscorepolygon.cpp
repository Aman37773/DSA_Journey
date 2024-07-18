#include<bits/stdc++.h>
using namespace std;

int solve(int n,int a[],int i,int j){

if(i+1==j){
    return 0;
}
int ans=INT_MAX;
for(int k=i+1;k<j;k++){
int get=a[i]*a[k]*a[j] + solve(n,a,i,k) + solve(n,a,k,j);
ans=min(ans,get);
}
return ans;
}

int main(){
int n,a[100];
cout<<"enter n: ";
cin>>n;
cout<<"enter values of vertex: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}
cout<<solve(n,a,0,n-1);
return 0;
}