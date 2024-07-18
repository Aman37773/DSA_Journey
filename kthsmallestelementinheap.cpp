#include<bits/stdc++.h>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;

heap(){
    arr[0]=-1;
    size=0;
}

void inserty(){     //0(n)
int index=size;
while(index!=1){
    if(arr[index/2]<arr[index]){
       swap(arr[index/2],arr[index]);     //important thing about node *this thing
        index=index/2;
    }
    else{
        break;
    }
}
return;
}

void insert(int data){    
size=size+1;
arr[size]=data;
return;
}

void deletion(){     //0(logn)
    if(size==0){
        cout<<"nothing to delete";
        return;
    }
arr[1]=arr[size];
--size;
int index=1;
while(2*index<=size){
if(arr[index]<arr[2*index]&&(2*index+1>size||arr[index]>=arr[2*index+1])){
    swap(arr[index],arr[2*index]);
    index=2*index;
}
else if(2*index+1<=size&&arr[index]<arr[2*index+1]&&arr[index]>arr[2*index]){
    swap(arr[index],arr[2*index+1]);
    index=2*index+1;
}
else if(arr[index]<arr[2*index]&&arr[index]<arr[2*index+1]){
    if(arr[2*index]>=arr[2*index+1]){
        swap(arr[index],arr[2*index]);
        index=2*index;
    }
    else if(arr[2*index]<arr[2*index+1]){
        swap(arr[index],arr[2*index+1]);
        index=2*index+1;
    }
}
else{
    break;
}
}
return;
}


void display(heap a){
    int i=1;
while(i<=size){
cout<<arr[i]<<" ";
++i;
}

return;
}


};




int main(){
heap a,b;
int n=0;
while(1){
int data;
cout<<"enter data: ";
cin>>data;
if(data==-1){
    break;
}
a.insert(data);
++n;
}

int k=4;
for(int i=0;i<k;i++){
    b.size=b.size+1;
    b.arr[b.size]=a.arr[b.size];
b.inserty();
}
for(int i=k+1;i<n;i++){
    if(b.arr[1]>a.arr[k+1]){
        b.deletion();
        b.size=b.size+1;
        b.arr[b.size]=a.arr[k+1];
        b.inserty();
    }
}
cout<<b.arr[1];
return 0;
}