#include<iostream>
#include<iomanip>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
char a[100]="abcd";
char c[100],b;
for(int i=0;i<strlen(a);i++){
if(i>0){
b=a[0];
a[0]=a[i];
a[i]=b;
}
for(int j=1;j<strlen(a)-1;j++){//1-2
for(int m=0;m<strlen(a)-j;m++){  //0-2 
for(int k=j;k<strlen(a);k++){ //1-3
if((k+m)%(strlen(a))<k){
c[(k+m)%(strlen(a))+j]=a[k];
}
else{
c[(k+m)%(strlen(a))]=a[k];
}
}
c[0]=a[0];
c[strlen(a)]='\0';
cout<<c<<endl;
}
}
}
return 0;
}