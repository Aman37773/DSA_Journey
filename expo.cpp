#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int value(int a,int b);
int main(){
int a,b;
cout<<"enter a and b: ";
cin>>a>>b;
cout<<value(a,b);

return 0;
}
int value(int a,int b){
if(b==1){
return a;
}
if(b==0){
return 1;
}
int ans=value(a,b/2);
if(b%2==0){
return ans*ans;
}
else if(b%2!=0){
return a*ans*ans;
}
}