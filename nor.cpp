#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
int main(){
int n,count=0;
cout<<"enter n: ";
cin>>n;
vector<bool> a(n+1,true);
for(int i=2;i<=n;i++){
if(a[i]==true){
count++;
for(int j=2*i;j<=n;j=j+i){//steve of eratosthenes
a[j]=false;
}
}
else{
continue;
}
}
cout<<count;
return 0;
}