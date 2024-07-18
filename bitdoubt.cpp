#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main(){
int n,c,m=1,b,k=0,p=0;
cout<<"enter n: ";
cin>>n;
while(n!=0){
c=n%10;
n=n/10;
p=p+c*pow(2,k);
k++;
}
b=p;

if(b==0){
cout<<0;
}

while(b!=0){
c=(b&1);
if(c==1){
m++;
}
b=(b>>1);
}
cout<<"number of times bit 1 appeared: "<<m-1;
return 0;
}//why not applicable for bigger values
//if can use modulo method only but also not applicable for bigger values
