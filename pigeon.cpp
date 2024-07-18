#include<iostream>
#include<iomanip>
#include<array>
#include<algorithm>
using namespace std;
int main(){
array<int,5> a={6,8,4,3,1};
array<int,6> b;
int n=5,k=1,sum=0,c,done;
b[0]=0;
for(int i=0;i<n;i++){
sum=sum+a[i];
b[k]=sum%n;
k++;
}
array<int,6> m(b);
sort(m.begin(),m.end());
for(int i=0;i<=n;i++){
if(m[i]=m[i+1]){
done=m[i];
break;
}
m.empty();
k=0;
for(int i=0;i<=n;i++){
if(b[i]==done){
m[k]=i;
k++;
}
if(k==2){
break;
}
}
cout<<a[m[0]]<<" to "<<a[m[1]-1];
return 0;
}