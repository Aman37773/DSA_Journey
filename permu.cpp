#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int value(string a,string b[],string c[],int i,int m,int iter,int iterr,int s,int bco,int set);
int main(){
string a="abcde";
string b[1000],c[1000];
int i=0,iter=0,m=a.length(),iterr=0,s=0,bco=0,set=0;//m=4
b[bco]=a.substr(iterr,iterr+1);
i++;
iterr=1;
int get=value(a,b,c,i,m,iter,iterr,s,bco,set);
for(int k=0;k<get;k++){
cout<<b[k]<<endl;
}
return 0;
}
int value(string a,string b[],string c[],int i,int m,int iter,int iterr,int s,int bco,int set){
if(s==b[0].length()+1){
bco++;
s=0;
}
if(iterr==bco){
for(int k=0;k<iter;k++){
b[k]=c[k];
}
set=iter;
iterr=iter;
bco=0;
iter=0;
i++;
}
if(i==a.length()){
return set;
}
c[iter]=b[bco].substr(0,s)+a.substr(i,1)+b[bco].substr(s,b[bco].length());
iter++;
s++;
int call=value(a,b,c,i,m,iter,iterr,s,bco,set);
return call;
}