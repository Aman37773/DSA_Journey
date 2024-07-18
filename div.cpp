#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main(){
int a=2,b=5,c=10,m=0,n=0,p=0;
for(int i=1;i<=500;i++){
if(i%2==0){
m++;
}
if(i%5==0){
n++;
}
if(i%2==0&&i%5==0){
p++;
}
}
cout<<m+n-p;
return 0;
}