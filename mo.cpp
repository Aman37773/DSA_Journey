#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
int main(){
array<int,6> a={1,2,3,4,5,6};
array<int,6> b;
int k=3,n=6;
for(int i=0;i<n;i++){
if(i+k<=n-1){
b.at(i+k)=a.at(i);
}
if(i+k>n-1){
b.at(i-k)=a.at(i);
}
}
for(int i=0;i<n;i++){
a.at(i)=b.at(i);
}
for(auto b=a.begin();b!=a.end();b++){
cout<<*b<<"\t";
}
return 0;
}
