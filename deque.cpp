#include<iostream>
#include<iomanip>
using namespace std;
int back=0,fronty=0;
void push_front(int data,int arr[]){
    arr[fronty]=data;
    ++fronty;
}

void push_back(int data,int arr[]){
    arr[back-1]=data;
    --back;
}

void pop_back(){
if(back==fronty){
    cout<<"already empty\n";
}
else{
    ++back;
}
}
void pop_front(){
if(back==fronty){
    cout<<"already empty\n";
}
else{
    --fronty;
}
}
void front(int arr[]){
if(back==fronty){
    cout<<"already empty\n";
}
else {
    cout<<arr[back]<<endl;
}
}
void isempty(){
if(back==fronty){
    cout<<"yes\n";
}
else{
    cout<<"no\n";
}
}
void size(){
cout<<fronty-back<<endl;
}

int main(){
int arr[100],capacity,operation,data;
cout<<"enter capacity: ";
cin>>capacity;
while(1){
cout<<"enter operation 1-push_front,2-pop_back,3-front,4-isempty,5-size,6-push_back,7-pop_front,8-exit: ";
cin>>operation;
if(operation==1){
    if(fronty==capacity){
        cout<<"already full\n";
    }
    else{
        cout<<"enter data: ";
        cin>>data;
        push_front(data,arr);
    }
}
else if(operation==2){
    pop_back();
}
else if(operation==3){
    front(arr);
}
else if(operation==4){
    isempty();
}
else if(operation==5){
    size();
}
else if(operation==6){
    if(back==0){
        cout<<"cannot insert\n";
    }
    else{
        cout<<"enter data: ";
        cin>>data;
        push_back(data,arr);
    }
}
else if(operation==7){
   pop_front();
}
else if(operation==8){
    break;
}
}
return 0;
}