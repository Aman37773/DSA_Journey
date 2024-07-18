#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
int value(int i,int n,int iter,int mrrcount,int prrcount,char *arr,char *prr,char *mrr,char *addrr,int addrrcount);
int main(){
char arr[]="amntk";
int i=0,n=strlen(arr),iter=0,mrrcount=0,prrcount=0,addrrcount=0;
char prr[1000],mrr[1000],addrr[1000];
prr[iter]=arr[i];
iter++;
mrrcount++;
prr[iter]='@';
iter++;
mrrcount++;
prr[iter]=' ';
iter++;
mrrcount++;
prr[iter]='@';
mrrcount++;
for(int k=0;k<=iter;k++){
mrr[k]=prr[k];
}
i++;
prrcount=mrrcount; 
mrrcount=0;
iter=0;
int get=value(i,n,iter,mrrcount,prrcount,arr,prr,mrr,addrr,addrrcount);
for(int k=0;k<get;k++){
if(mrr[k]=='@'){
cout<<endl;
continue;
}
cout<<mrr[k];
}
return 0;
}
int value(int i,int n,int iter,int mrrcount,int prrcount,char *arr,char *prr,char *mrr,char *addrr,int addrrcount){
int final;
if(mrrcount==prrcount){
prrcount=iter;
mrrcount=0;
for(int k=0;k<iter;k++){
mrr[k]=prr[k];
}
final=iter;
iter=0;
i++;
}
if(i==n){
return final;
}
if(mrr[mrrcount]=='@'){
mrrcount++;
}
else if(mrr[mrrcount]==' '){
prr[iter]=arr[i];
iter++;
prr[iter]='@';
iter++;
prr[iter]=' ';
iter++;
prr[iter]='@';
iter++;
mrrcount++;
}
else{
if(mrr[mrrcount+1]=='@'){
prr[iter]=mrr[mrrcount];
addrr[addrrcount]=mrr[mrrcount];
iter++;
prr[iter]=arr[i];
iter++;
prr[iter]='@';
iter++;
mrrcount++;
for(int k=0;k<=addrrcount;k++){
prr[iter]=addrr[k];
iter++;
}
prr[iter]='@';
iter++;
addrrcount=0;
}
else{
prr[iter]=mrr[mrrcount];
addrr[addrrcount]=mrr[mrrcount];
addrrcount++;
iter++;
mrrcount++;
}
}
int h=value(i,n,iter,mrrcount,prrcount,arr,prr,mrr,addrr,addrrcount);
return h;
}
