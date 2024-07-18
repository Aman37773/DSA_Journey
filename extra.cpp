#include<iostream>
#include<iomanip>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
char a[100],b;
int m=0;
cin.getline(a,100);
for(int i=0;i<strlen(a);i++){
b=a[i];
m=0;
for(int k=i;k<strlen(a);k++){
if(b==a[k]){
m++;
}
else{
break;
}
}
if(m>1&&i==0){
for(int j=i;j<strlen(a);j++){
a[j]=a[j+m];
if(a[j+m]=='\0'){
break;
}
}
i--;
}
else if(m>1&&i>0){
for(int j=i;j<strlen(a);j++){
a[j]=a[j+m];
if(a[j+m]=='\0'){
break;
}
}
i--;
i--;
}
else if(m==1){
continue;
}
}
cout<<a;
return 0;
}