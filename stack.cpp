#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;
struct stack{
int capacity;
int *arr;
int index;
stack stackdef(int n){
capacity=n;
index=0;
arr=new int[capacity];
}
void push(int element){
if(index>capacity){
cout<<"sorry stack is full\t";
}
arr[index]=element;
index++;
}

void pop(){
if(index==0){
return;
}
else{
index--;
}
}

void topel(){
cout<<arr[index-1]<<"\t";
}

void size(){
cout<<index<<endl;
}

void isempty(){
if(index==0){
cout<<"yes\t";
}
else{
cout<<"no\t";
}
}
};

int main(){
stack s;
s.stackdef(5);
int n;
while(true){
cout<<"enter 1 to push, 2 to pop, 3 to top, 4 to size, 5 to isempty\t";
cin>>n;
if(n==1){
int element;
cout<<"enter element to push: \t";
cin>>element;
s.push(element);
}
else if(n==2){
s.pop();
}
else if(n==3){
s.topel();
}
else if(n==4){
s.size();
}
else if(n==5){
s.isempty();
}
}
return 0;
}