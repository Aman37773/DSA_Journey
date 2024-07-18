#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main(){
int a,b,ans=1,m;
cout<<"enter a and b: ";
cin>>a>>b;
cout<<"enter m: ";
cin>>m;
if(b&1){
ans=a;
}
b>>=1;
while(b){
a=long(a*a)%m;
if(b&1){
ans=long(ans*a)%m;
}
b>>=1;
}
cout<<ans;
return 0;
}