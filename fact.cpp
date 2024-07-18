#include<iostream>
#include<iomanip>
using namespace std;
int main(){
long long int n,m,product=1;
cout<<"enter n and m: ";
cin>>n>>m;
while(n!=0){
product=(product*n)%m;
n--;
}
cout<<product;
return 0;
}