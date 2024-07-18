#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
int main(){
char a[100],b[100];
int g=0,m=0;
cin.getline(a,100);
cin.getline(b,100);
for(int i=0;i<strlen(a);i++){
g=0;
m=0;
for(int j=0;j<strlen(b);j++){
for(int k=i;k<i+strlen(b);k++){
if(b[j]==a[k]){
m++;
if(m==strlen(b)){
cout<<"yes";
return 0;
}
break;
}
if(b[j]!=a[k]&&k==i+strlen(b)-1){
g=1;
break;
}
}
if(g==1){
break;
}
}
}
cout<<"no";
return 0;
}