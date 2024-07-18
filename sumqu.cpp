#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;
int min(queue<int> a,int m,int k,int value){
    if(m==k-1){
        return value;
    }
    if(a.front()<value){
        value=a.front();
    }
    a.pop();
    ++m;
    int get=min(a,m,k,value);
    return get;
}
int max(queue<int> a,int m,int k,int value){
    if(m==k-1){
        return value;
    }
    if(a.front()>value){
        value=a.front();
    }
    a.pop();
    ++m;
    int get=max(a,m,k,value);
    return get;
}
int main(){
int n,data,k,m=0;
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
for(int i=0;i<n-k+1;i++){
int value=a.front();
a.pop();
cout<<min(a,m,k,value)+max(a,m,k,value)<<" ";
}
return 0;
}