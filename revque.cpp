#include<iostream>
#include<iomanip>
#include<queue>
#include<stack>
using namespace std;
int main(){
int n,data;
queue<int> a;
stack<int> b;
cout<<"enter n: ";
cin>>n;
cout<<"enter elements: ";
for(int i=0;i<n;i++){
cin>>data;
a.push(data);
}
for(int i=0;i<n;i++){
b.push(a.front());
a.pop();
}
for(int i=0;i<n;i++){
cout<<b.top()<<"\t";
b.pop();
}

return 0;
}
