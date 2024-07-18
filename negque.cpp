#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;
int check(queue<int> a,int m,int k){
    if(a.front()<0){
        return a.front();
    }
    else if(m==k-1){
        return 0;
    }
    a.pop();
    ++m;
    int value=check(a,m,k);
    return value;
}
int main(){
int n,data,k;
queue<int> a;
cout<<"enter n: ";
cin>>n;
cout<<"enter elements: ";
for(int i=0;i<n;i++){
    cin>>data;
    a.push(data);
}
cout<<"enter k: ";
cin>>k;
int m=0;
for(int i=0;i<n-k+1;i++){
cout<<check(a,m,k)<<"\t";
a.pop();
}
return 0;
}