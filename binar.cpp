#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int value(int *arr,int key,int n,int a,int b);
int main(){
int arr[]={1,3,5,6,9,11,13,16,19};
int key=111;
int n=9/2,a=0,b=8;
int got=value(arr,key,n,a,b);
if(got==0){
cout<<"not got it";
}
else{
cout<<"got it";
}
return 0;
}
int value(int *arr,int key,int n,int a,int b){
int p;
if(n==a||n==b){
p=0;
return p;
}
if(key>arr[n]){
a=n;
n=(a+b+1)/2;
}
 if(key<arr[n]){
b=n;
n=(a+b)/2;
}
 if(key==arr[n]){
p=1;
return p;
}
p=value(arr,key,n,a,b);
return p;
}