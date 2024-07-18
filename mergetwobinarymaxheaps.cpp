#include<bits/stdc++.h>
using namespace std;
class maxheap{
    public:
    int arr[100];
    int size;

maxheap(){
    arr[0]=-1;
    size=0;
}

void insert(int data){     
size=size+1;
arr[size]=data;
int index=size;
while(index!=1){
    if(arr[index/2]<arr[index]){
       swap(arr[index/2],arr[index]);    
        index=index/2;
    }
    else{
        break;
    }
}
return;
}

void display(maxheap a){
    int i=1;
while(i<=size){
cout<<arr[i]<<" ";
++i;
}

return;
}


};




int main(){
maxheap a,b;
int n=0;
cout<<"enter data for first heap: \n";
while(1){
int data;
cout<<"enter data: ";
cin>>data;
if(data==-1){
    break;
}
a.insert(data);
}
cout<<"enter data for second heap: \n";
while(1){
int data;
cout<<"enter data: ";
cin>>data;
if(data==-1){
    break;
}
b.insert(data);
++n;
}

for(int i=1;i<=n;i++){
    a.insert(b.arr[i]);
}


a.display(a);



return 0;
}