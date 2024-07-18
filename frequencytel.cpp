#include<iostream>
#include<iomanip>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
char a[100],b,count='0';
int m=0,h;
cin.getline(a,100);
for(int i=0;i<strlen(a);i++){
b=a[i];
m=0;
count='0';
for(int j=i;j<strlen(a);j++){
if(b==a[j]){
m++;
count++;
}
else{
break;
}
}
if(m>1){
a[i+1]=count;
h=i;
for(int k=i+m;k<=strlen(a);k++){
a[h+2]=a[k];
h++;
}
i++;
}
else if(m==1){
continue;
}
}
cout<<a;
return 0;
}