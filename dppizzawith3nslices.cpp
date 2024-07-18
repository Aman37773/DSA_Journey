#include<bits/stdc++.h>
using namespace std;


int solve(int n,int a[],int m,int count,int net){
if(count==net/3||m>=n){
    return 0;
}

int get=0,maxy=0;
for(int i=m;i<n;i++){
    
get=a[i]+solve(n,a,i+2,count+1,net);
maxy=max(maxy,get);
    
}
return maxy;
}


int main(){
int n,a[100];  //multiple of 3
cout<<"enter n: ";
cin>>n;
cout<<"enter slice values: ";
for(int i=0;i<n;i++){
cin>>a[i];
}

int get1=solve(n-1,a,0,0,n);


int get2=solve(n,a,1,0,n);

cout<<max(get1,get2);
return 0;
}