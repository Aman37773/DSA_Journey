#include<bits/stdc++.h>
using namespace std;
int solve(int n,int k){

if(n<0){
    return 0;
}
if(n==1||n==0){
    return k;
}


int get=solve(n-1,k)*k-solve(n-3,k);
return get;
}


int main(){
int n,k;  //number of fence and colour  
cout<<"enter n: ";
cin>>n;
cout<<"enter k: ";
cin>>k;
cout<<solve(n,k);
return 0;
}