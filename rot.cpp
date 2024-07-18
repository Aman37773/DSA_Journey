#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
int main(){
array<int,6> a={1,2,3,4,5,6};
array<int,6> b;
int k=6,n=6,m;
for(int i=0;i<n;i++){
b.at((i+k)%n)=a.at(i);
}
for(int i=0;i<n;i++){
a.at(i)=b.at(i);
}
for(auto b=a.begin();b!=a.end();b++){
cout<<*b<<"\t";
}
return 0;
}
