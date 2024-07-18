#include<bits/stdc++.h>
using namespace std;

int solve(int n,int x,int y,int z){
if(n<0){
    return INT_MIN;
}
if(n==0){
    return 0;
}
    int get1=solve(n-x,x,y,z);
    int get2=solve(n-y,x,y,z);
    int get3=solve(n-z,x,y,z);
    return max(max(get1,get2),get3)+1;
}



int main(){
int n;
cout<<"ener n: ";
cin>>n;
int x,y,z;
cout<<"enter x,y,z: ";
cin>>x>>y>>z;

cout<<solve(n,x,y,z);
return 0;
}