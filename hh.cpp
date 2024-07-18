#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int value(int a,int b,int n);

int main(){
int a=1,b=1,n;
cout<<"enter n: ";
cin>>n;
cout<<a<<"\t";
value(a,b,n);
return 0;
}

int value(int a,int b,int n){
if(n==1){
return 0;
}
  int  c=a;
  cout<<c<<"\t";
  n--;
int num=value(a+b,c,n);
return 0;
}