#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;
void value(stack<int> &b,int arr[],int i){
   int data;
if(b.empty()==1){
    cout<<"-1\t";
    return;
}
if(b.top()>=arr[i]){
   data=b.top();
b.pop();
}
else if(b.top()<arr[i]){
    cout<<b.top()<<"\t";
    return;
}
value(b,arr,i);
b.push(data);
return;
}

int main(){
int arr[100],size;
stack<int> b;
cout<<"enter size: ";
cin>>size;
cout<<"enter elements: ";
for(int i=0;i<size;i++){
    cin>>arr[i];
}
for(int i=size-1;i>=0;i--){
    b.push(arr[i]);
    value(b,arr,i);
}

return 0;
}