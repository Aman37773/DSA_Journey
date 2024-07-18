#include<iostream>
#include<iomanip>
#include<queue>
#include<stack>
using namespace std;
int main(){
queue<int> a;
stack<int> b;
int n,data,k;
cout<<"enter n: ";
cin>>n;
cout<<"enter elements: ";
for(int i=0;i<n;i++){
cin>>data;
a.push(data);
}
cout<<"enter k: ";
cin>>k;
for(int i=0;i<k;i++){
b.push(a.front());
a.pop();
}
for(int i=0;i<k;i++){
    a.push(b.top());
    b.pop();
}
for(int i=0;i<n-k;i++){
    a.push(a.front());
    a.pop();
}
for(int i=0;i<n;i++){
    cout<<a.front()<<"\t";
    a.pop();
}

return 0;
}