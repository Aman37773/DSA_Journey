#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main(){
int n;
cout<<"enter n: ";
cin>>n;
if(n==1){
cout<<"non-prime";
return 0;
}

for(int i=2;i<n;i++){
if(n%i==0){
cout<<"non-prime";
return 0;
}
}
cout<<"prime";
return 0;
}