#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int top=0;
void push(int arr[],int data,int size){
    if(top>size-1){
        cout<<"already full";
        return;
    }
arr[top]=data;
++top;
}
void pop(){
if(top==0){
cout<<"already empty";
return;
}
    --top;
}
int getmin(int arr[]){
    if(top==0){
cout<<"already empty";
return 0;
}
    int minval=arr[0];
    for(int i=0;i<top;i++){
        minval=min(minval,arr[i]);
    }
    return minval;
}

int main(){
int arr[100],size;
cout<<"enter size: ";
cin>>size;
push(arr,10,size);
push(arr,20,size);
push(arr,30,size);
cout<<getmin(arr)<<endl;
push(arr,0,size);
pop();
cout<<getmin(arr)<<endl;
return 0;
}
//0(n),0(n)