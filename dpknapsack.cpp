#include<bits/stdc++.h>
using namespace std;


int solve(int n,int v[],int w[],int weight,int &limit){
    if(weight>limit){
    return INT_MIN;
}
if(n<0){
    return 0;
}
    int inc=v[n]+solve(n-1,v,w,weight+w[n],limit);
    int ex=solve(n-1,v,w,weight,limit);
    return max(inc,ex);
}


int main(){
int n,v[100],w[100],limit;

cout<<"enter n: ";
cin>>n;
cout<<"enter values: ";
for(int i=0;i<n;i++){
    cin>>v[i];
}
cout<<"enter weight: ";
for(int i=0;i<n;i++){
    cin>>w[i];
}
cout<<"enter limit: ";
cin>>limit;

cout<<solve(n-1,v,w,0,limit);




return 0;
}

//////////how 2d array implemented