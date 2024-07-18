#include<iostream>
#include<iomanip>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
char a[100],b[100],high;
int m=0,c=0;
cin.getline(a,100);
for(int i=0;i<strlen(a);i++){
b[i]=a[i];
m=0;
for(int j=0;j<strlen(a);j++){
if(b[i]==a[j]){
m++;
}
}
if(m>c){
c=m;
high=b[i];
}
}
cout<<high<<" appeared maximum times and appeared  "<<c<<" times";
return 0;
}

