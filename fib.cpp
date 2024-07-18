#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int value(int a,int b,int n);
int main(){
int a=0,b=1,n;
cout<<"enter n: ";
cin>>n;
value(a,b,n);
return 0;
}
int value(int a,int b,int n){
if(n==0){
return 0;
}
int c=a;
  cout<<a<<"\t";
  n--;
int num=value(a+b,c,n);
return 0;
}
