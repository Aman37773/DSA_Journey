#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int value(int n);
int main(){
int n;
cout<<"enter n: ";
cin>>n;
value(n);
return 0;
}

int value(int n){
if(n==0||n==1){
return n;
}
int a=value(n-1)+value(n-2);
cout<<a<<"\t";
return a;
}