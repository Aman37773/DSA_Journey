#include<iostream>
#include<iomanip>
using namespace std;
int main(){
int a[100][100],m,n,k=0,p=0,r=0;
int value=0,total,s,count=0;
cout<<"enter number of rows and coloumn: ";
cin>>m>>n;
total=m*n;
if(m<n&&m%2==0){
s=m/2;
}
else if(m<n&&m%2!=0){
s=m/2+1;
}
else if(m>n&&n%2==0){
s=n/2;
}
else if(m>n&&n%2!=0){
s=n/2+1;
}
else if(m==n&&m%2==0){
s=m/2;
}
else if(m==n&&m%2!=0){
s=m/2+1;
}
cout<<"enter matrix elements: ";
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
cin>>a[i][j];
}
}
while(count!=s){
r++;
n--;
m--;
while(1){
cout<<a[k][p];
value++;
if(value==total){
return 0;
}
if(p<n){
p++;
}
else{
k++;
break;
}
}
while(1){
cout<<a[k][p];
value++;
if(value==total){
return 0;
}
if(k<m){
k++;
}
else{
p--;
break;
}
}
while(1){
cout<<a[k][p];
value++;
if(value==total){
return 0;
}
if(p>=r){          
p--;
}
else{
k--;
break;
}
}
while(1){
cout<<a[k][p];
value++;
if(value==total){
return 0;
}
if(k>r){
k--;
}
else{
p++;
break;
}
}
count++;
}
return 0;
}