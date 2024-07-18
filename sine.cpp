#include<iostream>
#include<iomanip>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
int a[100][100],m,n;
cout<<"enter number of rows and coloumn: ";
cin>>m>>n;
cout<<"enter matrix elements: ";
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
cin>>a[i][j];
}
}

for(int i=0;i<n;i++){
if(i%2==0){
for(int j=0;j<m;j++){
cout<<a[j][i]<<"\t";
}
}
if(i%2!=0){
for(int j=m-1;j>=0;j--){
cout<<a[j][i]<<"\t";
}
}
}
return 0;
} 