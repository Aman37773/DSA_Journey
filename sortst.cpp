#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;
void sort(stack<int> &a,int num){
    if(a.empty()==1){
a.push(num);
return;
    }
if(a.top()>num){
    int data=a.top();
    a.pop();
    sort(a,num);
    a.push(data);
    return;
}
if(a.top()<=num){
    a.push(num);
    return;
}
}
void value(stack<int> &a){
    if(a.empty()==1){
        return;
    }
    int num=a.top();
    a.pop();
    value(a);
    sort(a,num);
    return;
}

int main(){
int capacity,data;
stack<int> a;
cout<<"enter capacity: ";
cin>>capacity;
cout<<"enter data: ";
for(int i=0;i<capacity;i++){
    cin>>data;
    a.push(data);
}
value(a);
while(a.empty()!=1){
    cout<<a.top()<<"\t";
    a.pop();
}
return 0;
}