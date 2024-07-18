#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;
void rev(queue<int> &a){
    if(a.empty()==1){
        return;
    }
    int value=a.front();
    a.pop();
    rev(a);
    a.push(value);
}
int main(){
int n,data;
queue<int> a;
cout<<"enter n: ";
cin>>n;
cout<<"enter elements: ";
for(int i=0;i<n;i++){
cin>>data;
a.push(data);
}
rev(a);
for(int i=0;i<n;i++){
cout<<a.front()<<"\t";
a.pop();
}
return 0;
}
