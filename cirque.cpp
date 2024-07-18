#include<iostream>
#include<iomanip>
using namespace std;
int back=0,fronty=0;
void push(int data,int arr[],int &m,int capacity){
    arr[fronty]=data;
    ++fronty;
    if(fronty==capacity&&back>0){
        fronty=0;
    }
    if(m<5){
    ++m;
    }
}
void pop(int &m,int capacity){
if(m==0){
    cout<<"already empty\n";
}
else{
    ++back;
    if(back==capacity){
        back=0;
    }
    if(m>0){
    --m;
    }
}
}
void front(int arr[],int &m){
if(m==0){
    cout<<"already empty\n";
}
else{
    cout<<arr[back]<<endl;
}
}
void isempty(int &m){
if(m==0){
    cout<<"yes\n";
}
else{
    cout<<"no\n";
}
}
void size(int &m){
cout<<m<<endl;
}

int main(){
int arr[100],capacity,operation,data,m=0;
cout<<"enter capacity: ";
cin>>capacity;
while(1){
cout<<"enter operation 1-push,2-pop,3-front,4-isempty,5-size,6-exit: ";
cin>>operation;
if(operation==1){
    if(m==capacity){
        cout<<"already full\n";
        continue;
    }
    if(fronty==capacity&&back>0){
        fronty=0;
    }
        cout<<"enter data: ";
        cin>>data;
        push(data,arr,m,capacity);
    }
else if(operation==2){
    pop(m,capacity);
}
else if(operation==3){
    front(arr,m);
}
else if(operation==4){
    isempty(m);
}
else if(operation==5){
    size(m);
}
else if(operation==6){
    break;
}
}
return 0;
}