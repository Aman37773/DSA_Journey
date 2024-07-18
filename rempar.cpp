#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
int main(){
char a[100],b[100],c[100];
int s=0,m,n;
cin.getline(a,100);
cin.getline(b,100);
m=strlen(a);
n=strlen(b);
for(int i=0;i<m;i++){
s=0;
if(a[i]==b[0]){
for(int p=i;p<i+n;p++){
c[s]=a[p];
s++;
}
c[s]='\0';
}
else{
continue;
}
if(strcmp(c,b)==0){
for(int k=i;k<m;k++){
if(a[k+n]=='\0'){
a[k]='\0';
break;
}
else{
a[k]=a[k+n];
}
}
for(int g=0;g<strlen(b);g++){
i--;
}
if(i<-1){
i=-1;
}
}
}
cout<<a;
return 0;
}