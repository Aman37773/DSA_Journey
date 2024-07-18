#include<iostream>
#include<iomanip>
#include<deque>
using namespace std;
void insert(deque<int> &a,deque<int> &b,int i,int m){
if(m<=i){
    int value=a.front();
    a.pop_front();
    ++m;
    insert(a,b,i,m);
    a.push_front(value);
    return;
}
else{
    a.push_front(b.front());
    b.pop_front();
return;
}
}
int main(){
int n,data,m=0;
deque<int> a,b;
cout<<"enter n: ";//even
cin>>n;
cout<<"enter elements: ";
for(int i=0;i<n;i++){
cin>>data;
a.push_back(data);
if(i>=n/2){
b.push_back(data);
}
}
for(int i=0;i<n;i=i+2){
    insert(a,b,i,m);
}
for(int i=0;i<n/2;i++){
    a.pop_back();
}
for(int i=0;i<n;i++){
   cout<<a.front()<<" ";
a.pop_front();
}

return 0;
}