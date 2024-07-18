#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int top=0,minn;
void push(int arr[],int data,int size){
    if(top>size-1){
        cout<<"already full";
        return;
    }
    if(top==0){
arr[top]=data;
++top;
minn=arr[0];
        return;
    }
    if(data>=minn){
arr[top]=data;
++top;
    }
    else{
        arr[top]=2*data-minn;
         minn=min(minn,data);
         ++top;
    }
   
}
void pop(int arr[]){
if(top==0){
cout<<"already empty";
return;
}
if(arr[top-1]>=minn){
    --top;
}
else{
minn=2*minn-arr[top-1];
--top;
}
}
int getmin(){
    cout<<minn<<endl;
}

int main(){
int arr[100],size;
cout<<"enter size: ";
cin>>size;
push(arr,10,size);
push(arr,15,size);
push(arr,5,size);
getmin();
push(arr,0,size);
getmin();
pop(arr);
getmin();
pop(arr);
getmin();
return 0;
}
