#include<iostream>
#include<iomanip>
using namespace std;
int topp=0;
int capacity;
void push(int data,int *arr){   
arr[topp]=data;
topp++;
}
void pop(){
        --topp;
}
void top(int *arr){
    cout<<arr[topp-1]<<"\n";
}
void empty(){
    if(topp==0){
        cout<<"yes\n";
        return;
    }
        cout<<"no\n";
}
void size(){
  cout<<topp<<endl;  
}
int main(){
int arr[100],operation,data;
cout<<"enter capacity: ";
cin>>capacity;
while(1){
cout<<"enter operation 1-push,2-pop,3-top,4-empty,5-size,6-done: ";
cin>>operation;
if(operation==1){
if(topp==capacity){
        cout<<"already full\n";
        continue;
}
    cout<<"enter data: ";
    cin>>data;
push(data,arr);
}
if(operation==2){
if(topp==0){
        cout<<"already empty\n";
        continue;
    }
    pop();
}
if(operation==3){
if(topp==0){
        cout<<"already empty\n";
        continue;
    }
    top(arr);
}
if(operation==4){
empty();
}
if(operation==5){
    size();
}
if(operation==6){
    cout<<"done\n";
    break;
}
}
return 0;
}