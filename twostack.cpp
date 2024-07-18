#include<iostream>
#include<iomanip>
using namespace std;
int topp1=0,topp2=0;
int capacity1,capacity2;
void push1(int data,int *arr){   
arr[topp1]=data;
topp1++;
}
void pop1(){
        --topp1;
}
void top1(int *arr){
    cout<<arr[topp1-1]<<"\n";
}
void empty1(){
    if(topp1==0){
        cout<<"yes\n";
        return;
    }
        cout<<"no\n";
}
void size1(){
  cout<<topp1<<endl;  
}

void push2(int data,int *arr){   
arr[topp2]=data;
topp2--;
}
void pop2(){
        ++topp2;
}
void top2(int *arr){
    cout<<arr[topp2+1]<<"\n";
}
void empty2(){
    if(topp2==capacity1+capacity2){
        cout<<"yes\n";
        return;
    }
        cout<<"no\n";
}
void size2(){
  cout<<capacity1+capacity2-topp2<<endl;  
}

int main(){
int arr[100],operation,data;
int stack;
cout<<"enter capacity 1 and 2: ";
cin>>capacity1>>capacity2;
topp2=capacity1+capacity2;
while(1){
cout<<"enter 1(stack1) or 2(stack2): ";
cin>>stack;
if(stack==1){
while(1){
cout<<"enter operation 1-push,2-pop,3-top,4-empty,5-size,6-done: ";
cin>>operation;
if(operation==1){
if(topp1==capacity1){
        cout<<"already full\n";
        continue;
}
    cout<<"enter data: ";
    cin>>data;
push1(data,arr);
}
if(operation==2){
if(topp1==0){
        cout<<"already empty\n";
        continue;
    }
    pop1();
}
if(operation==3){
if(topp1==0){
        cout<<"already empty\n";
        continue;
    }
    top1(arr);
}
if(operation==4){
empty1();
}
if(operation==5){
    size1();
}
if(operation==6){
    cout<<"done\n";
    break;
}
}
}
if(stack==2){
  while(1){
cout<<"enter operation 1-push,2-pop,3-top,4-empty,5-size,6-done: ";
cin>>operation;
if(operation==1){
if(topp2==capacity1){
        cout<<"already full\n";
        continue;
}
    cout<<"enter data: ";
    cin>>data;
push2(data,arr);
}
if(operation==2){
if(topp2==capacity1+capacity2){
        cout<<"already empty\n";
        continue;
    }
    pop2();
}
if(operation==3){
if(topp2==capacity1+capacity2){
        cout<<"already empty\n";
        continue;
    }
    top2(arr);
}
if(operation==4){
empty2();
}
if(operation==5){
    size2();
}
if(operation==6){
    cout<<"done\n";
    break;
}
}  
}
}
return 0;
}