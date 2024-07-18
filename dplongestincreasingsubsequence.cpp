#include<bits/stdc++.h>
using namespace std;

int solve(int n,int a[],int m,int val){
if(m+1==n){
    return 0;
}
int get=0,maxy=0;
for(int i=m+1;i<n;i++){
    if(a[i]>val){
     get = solve(n,a,i,a[i])+1;
     maxy=max(maxy,get);
    }
}
return maxy;
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
for(int i=0;i<n;i++){
maxy=max(maxy,solve(n,a,i,a[i])+1);
}
cout<<maxy;
return 0;
}