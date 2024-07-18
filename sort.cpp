#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int value(int *arr,int n);
int main(){
int arr[]={1,2,5,6,7};
int b=value(arr,5);
if(b==0){
    cout<<"no";
}
else{
cout<<"yes";
}
return 0;
}
int value(int *arr,int n){
if(n==0){
return 1;
}
n--;
int p=value(arr,n);
if(p==0){
return 0;
}
if(arr[n]>arr[n+1]&&n!=4){
return 0;
}
return 1;
}