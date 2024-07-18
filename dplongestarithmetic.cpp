#include<bits/stdc++.h>
using namespace std;

int solve(int n,int a[],int m,int cur,int diff){  
if(m==n){
    return 1;
}
int get=0,maxy=1;
for(int i=m;i<n;i++){
if(diff==-1||a[i]-a[cur]==diff){
get=solve(n,a,i+1,i,a[i]-a[cur])+1;
maxy=max(maxy,get);
//cout<<maxy<<"\t";
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
int get=solve(n,a,i+1,i,-1);
maxy=max(maxy,get);
}
cout<<maxy;
return 0;
}