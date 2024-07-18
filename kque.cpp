#include<iostream>
#include<iomanip>
using namespace std;
void push(int arr[],int next[100],int front[100],int back[100],int &i,int data,int &free,int que){
i=free;
free=next[i];
if(front[que-1]==-1){
front[que-1]=i;
back[que-1]=i;
next[i]=-1;
}
else{
next[back[que-1]]=i;
back[que-1]=i;
next[i]=-1;
}
arr[i]=data;
return;
}

void pop(int next[100],int front[100],int que){
    if(front[que-1]==-1){
        cout<<"already empty\n";
    }
    else{
        front[que-1]=next[front[que-1]];
    }
    return;
}
void display(int arr[],int front[],int que){
    if(front[que-1]==-1){
        cout<<"already empty\n";
        return;
    }
cout<<arr[front[que-1]]<<"\n";
}



int main(){
int n,k,arr[100],next[100],front[100],back[100],free=0,i=0,que,data,operation;
cout<<"enter n: ";
cin>>n;
cout<<"enter k: ";
cin>>k;
for(int i=0;i<n;i++){
    if(i==n-1){
        next[i]=-1;
        continue;
    }
    next[i]=i+1;
}
for(int i=0;i<k;i++){
    front[i]=-1;
    back[i]=-1;
}
while(1){
cout<<"enter que: ";
cin>>que;
cout<<"enter operation 1-push,2-pop,3-display,4-exit: ";
cin>>operation;
    if(operation==1){
        if(free==-1){
        cout<<"already full\n";
        continue;
    }
        cout<<"enter data: ";
        cin>>data;
push(arr,next,front,back,i,data,free,que);
    }
if(operation==2){
pop(next,front,que);
}
if(operation==3){
    display(arr,front,que);
}
if(operation==4){
    break;
}
}

return 0;
}