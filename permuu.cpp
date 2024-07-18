#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;
int value(int i,int j,int cco,int iter,int iterr,string a,string b[],string c[]);
int main(){
string a="abcd";
string b[1000],c[1000];
c[0]=a;
int i=0,j=0,cco=0,iter=0,iterr=0;
iterr=1;
int gotcha=value(i,j,cco,iter,iterr,a,b,c);
for(int k=0;k<gotcha;k++){
cout<<c[k]<<endl;
}
return 0;
}
int value(int i,int j,int cco,int iter,int iterr,string a,string b[],string c[]){
int got;
if(j==a.length()){
cco++;
j=i;
}
if(cco==iterr){
iterr=iter;
for(int k=0;k<iter;k++){
c[k]=b[k];
}
got=iter;
cco=0;
i++;
j=i;
iter=0;
}
if(i==a.length()-1){
return got;
}
swap(c[cco][i],c[cco][j]);
b[iter]=c[cco];
swap(c[cco][i],c[cco][j]);
j++;
iter++;
int call=value(i,j,cco,iter,iterr,a,b,c);
return call;
}

