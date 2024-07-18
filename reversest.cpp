#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
int value(char *arr,int n);
int main(){
char arr[]="lundkabaal";
int n=strlen(arr);
value(arr,n);
return 0;
}
int value(char *arr,int n){
if(n==-1){
return 0;
}
cout<<arr[n];
n--;
value(arr,n);
return 0;
}