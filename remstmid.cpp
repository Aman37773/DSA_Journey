#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;
void value(stack<int> &a,int size){
if(a.size()==size/2){
    a.pop();
    return;
}
int num=a.top();
a.pop();
value(a,size);
a.push(num);
return;
}

int main(){
stack<int> a;
a.push(5);
a.push(4);
a.push(3);
a.push(2);
a.push(1);
int size=a.size()+1;
value(a,size);
while(a.size()){
cout<<a.top()<<"\t";
a.pop();
}
return 0;
}