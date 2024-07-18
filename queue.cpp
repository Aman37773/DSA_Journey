#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
struct queue{
int *arr;
int capacity;
int frontindex;
int backindex;
queue queuedef(int n){
arr=new int[n];
capacity=n;
frontindex=0;
backindex=0;
}
void enqueue(){
if(frontindex>capacity){
cout<<"already full\t";
}
else{
    int element;
cout<<"enter element\t";
cin>>element;
arr[frontindex]=element;
frontindex++;
}
}
void dequeue(){
if(frontindex-backindex==0){
cout<<"already empty\t";
}
else{
backindex++;
}
}
int top(){
if(frontindex-backindex==0){
cout<<"already empty\t";
}
return arr[backindex];
}
void size(){
cout<<frontindex-backindex;
}
void isempty(){
if(frontindex-backindex==0){
cout<<"empty\t";
}
else{
cout<<"no\t";
}
}
};

int main(){
queue a;
a.queuedef(5);
int n;
while(true){
cout<<"enter 1 to enqueue, 2 to dequeue, 3 to top, 4 to size, 5 to isempty\t";
cin>>n;
if(n==1){
a.enqueue();
}
else if(n==2){
a.dequeue();
}
else if(n==3){
cout<<a.top()<<"\t";
}
else if(n==4){
a.size();
}
else if(n==5){
a.isempty();
}
}


return 0;
}