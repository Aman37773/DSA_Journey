#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
int value(char *arr,int n,char *prr,int i);
int main(){
int i=0;
char prr[100];
char arr[]="loolol";
int n=strlen(arr)-1;
value(arr,n,prr,i);
if(strcmp(arr,prr)==0){
cout<<"yes";
}
else{
cout<<"no";
}
return 0;
}
int value(char *arr,int n,char *prr,int i){
if(n==-1){
return 0;
}
prr[i]=arr[n];
n--;
i++;
value(arr,n,prr,i);
prr[strlen(arr)]='\0';
return 0;
}