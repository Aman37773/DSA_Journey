#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;
class hello{
    public:
int arr[100];
int size;
int next[100];
int top[100];
int k;
int free=0,i=0;
hello(){
    cout<<"enter size: ";
cin>>size;
cout<<"enter k: ";
cin>>k;
for(int i=0;i<size;i++){
    if(i+1>size-1){
        next[i]=-1;
        continue;
    }
next[i]=i+1;
}
for(int i=0;i<k;i++){
    top[i]=-1;
}
}

void push(int data,int whichstack){
  i=free;
  if(i==-1){
    cout<<"full";
    return;
  }
  free=next[i];
next[i]=top[whichstack-1];
top[whichstack-1]=i;
arr[i]=data;
}

void pop(int whichstack){
    if(top[whichstack-1]==-1){
        cout<<"already empty";
        return;
    }
    int index=top[whichstack-1];
top[whichstack-1]=next[top[whichstack-1]];
next[index]=free;
free=index;
}

void display(int whichstack){
    if(top[whichstack-1]==-1){
        cout<<"already empty";
        return;
    }
cout<<arr[top[whichstack-1]]<<"\t";
}
};

int main(){
    hello a;
a.push(10,1);
a.push(20,2);
a.push(30,1);
a.push(40,2);
a.push(50,3);
a.pop(1);
a.display(1);
return 0;
}