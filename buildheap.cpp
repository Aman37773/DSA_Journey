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

void insert(int data){     //0(n)
size=size+1;
arr[size]=data;
int index=size;
while(index!=1){
    if(arr[index/2]<arr[index]){
       swap(arr[index/2],arr[index]);     //important thing about node *this thing(a.arr,arr)
        index=index/2;
    }
    else{
        break;
    }
}
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

void heapify(int largest,int n){   //0(n)
if(largest>=n/2+1){
    return;
}
int left=2*largest;
int right=2*largest+1;
if(arr[largest]>=arr[left]&&(right>n||arr[largest]>=arr[right])){
    return;
}
else if(arr[largest]<arr[left]&&(right>n||arr[largest]>=arr[right])){
    swap(arr[largest],arr[left]);
    heapify(2*largest,n);
    return;
}
else if(arr[largest]>arr[left]&&arr[largest]<=arr[right]){
    swap(arr[largest],arr[right]);
    heapify(2*largest+1,n);
    return;
}
else if(arr[largest]<arr[left]&&arr[largest]<arr[right]){
if(arr[left]>=arr[right]){
    swap(arr[largest],arr[left]);
    heapify(2*largest,n);
    return;
}
else if(arr[left]<arr[right]){
    swap(arr[largest],arr[right]);
    heapify(2*largest+1,n);
    return;
}
}
return;
}



void heapsort(int i){   //0(nlogn)
    int index=1;
    swap(arr[1],arr[i]);
    int s=i-1;
    while(2*index<=s){
if(arr[index]<=arr[2*index]&&(2*index+1>s||arr[index]>=arr[2*index+1])){
    swap(arr[index],arr[2*index]);
    index=2*index;
}
else if(2*index+1<=s&&arr[index]<arr[2*index+1]&&arr[index]>=arr[2*index]){
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
maxheap a;
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

//a.deletion();
 for(int i=n/2;i>=1;i--){
 a.heapify(i,n);
 }

// for(int i=n;i>1;i--){
//     a.heapsort(i);
// }


a.display(a);

//priority_queue<int> k;//this is similar to maxheap
// priority_queue<int,vector<int>,greater<int>> u;//this is similar to minheap
// u.push(4);
// u.push(2);
// u.push(7);
// cout<<u.top();
// u.pop();
// cout<<u.top();

return 0;
}