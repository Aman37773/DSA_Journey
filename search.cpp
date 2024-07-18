#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main(){
int a[100][100],b[100],m,n,k=0,in,out,mid,key;
int p,q;
cout<<"enter key: ";
cin>>key;
cout<<"enter number of rows and columns: ";
cin>>m>>n;
in=0;
out=m*n-1;
cout<<"enter matrix elements: ";
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
cin>>a[i][j];
}
}
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
b[k]=a[i][j];
k++;
}
}
mid=(in+out)/2;
while(1){
if(b[mid]>key){
out=mid;
mid=(in+out)/2;
}
else if(b[mid]<key){
in=mid;
mid=(in+out)/2+1;
}
else if(b[mid]==key){
break;
}
else if(mid==0||mid==m*n-1){
cout<<"not found";
return 0;
}
}
p=mid/n;
q=mid%n;
cout<<key<<"  is at index  "<<p<<"  ,  "<<q;

return 0;
}