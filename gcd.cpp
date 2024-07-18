#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main(){
int a,b;
cout<<"enter a and b: ";
cin>>a>>b;
while(a!=0&&b!=0){
if(a>b){
a=a-b;
}
else if(a<b){
b=b-a;
}
else if(a==b){
a=a-b;
}
}
if(a==0){
cout<<b;
}
else{
cout<<a;
}
return 0;
}