#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main(){
int a[100][100],b[100][100],m,n;
int k,count,angle,value=0,swap;
cout<<"enter angle: ";
cin>>angle;
count=angle/90;
cout<<"enter number of rows and coloumns: ";
cin>>m>>n;
cout<<"enter matrix elements: ";
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
cin>>a[i][j];
}
}
while(count!=value ){
k=m-1;
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
b[j][k]=a[i][j];
}
k--;
}
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
a[i][j]=b[i][j];
}
}
value++;
swap=m;
m=n;
n=swap;
}
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
cout<<b[i][j];
}
cout<<"\n";
}
return 0;
}