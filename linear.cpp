#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int value(int *arr,int key,int n);
int main(){
int arr[]={1,2,6,8,9};
int key=9,n=5;
int outcome=value(arr,key,n);
if(outcome==0){
cout<<"not got it";
}
else{
cout<<"got it";
}
return 0;
}
int value(int *arr,int key,int n){
int p;
if(n==0){
p=0;
return p;
}
if(key==arr[n-1]){
p=1;
return p;
}
n--;
p=value(arr,key,n);
return p;
}