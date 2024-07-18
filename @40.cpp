#include<iostream>
#include<iomanip>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
char a[100],b[100];
int m=0;
cin.getline(a,100);
cin.getline(b,100);
for(int i=0;i<strlen(a);i++){
if(a[i]==' '){
for(int j=strlen(a);j>i;j--){
a[j+strlen(b)]=a[j];
}
for(int k=i;k<i+strlen(b);k++){
a[k]=b[m];
m++;
}
}
}
cout<<a;
return 0;
}