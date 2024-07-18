#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int value(int n);
int main(){
int n;
cout<<"enter n: ";
cin>>n;
cout<<value(n);
    return 0;
    }
int value(int n){
if(n==0||n==1){
return 1;
}
int a=value(n-1)+value(n-2);
return a;
}
