#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
int main(){
char a[100],c;
  gets(a);
for(int i=0;i<strlen(a);i++){
c=a[i];
for(int j=i+1;j<strlen(a);j++){
if(c==a[j]){
cout<<"yes";
return 0;
}
}
}
cout<<"no";
}