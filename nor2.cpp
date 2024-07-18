#include<iostream>
#include<iomanip>
#include<vector>
#include<math.h>
using namespace std;
int main(){
int m,n,root,count=0,value=0;
cout<<"enter lower and upper limit: ";
cin>>m>>n;
root=pow(n,0.5);
vector<bool> a(n+1,true);
for(int i=m;i<=n;i++){
value=0;
for(int j=1;j<=i;j++){
if(i%j==0){
value++;
}
}
if(value==2){
m=i;
break;
}
}
for(int i=2;i<=root;i++){
if(a[i]==true){
for(int j=2*i;j<=n;j=j+i){
a[j]=false;
}
}
else{
continue;
}
}
for(int i=m;i<=n;i++){
if(a[i]==true){
count++;
}
}
cout<<count;
return 0;
}