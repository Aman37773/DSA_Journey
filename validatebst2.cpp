#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;
class node{
    public:
int data;
node *left;
node *right;

node(int data){
this->data=data;
this->right=NULL;
this->left=NULL;
}

node *buildtree(node *a,int d){ 
if(d==-1){
    return a;
}
if(a==NULL){
    a=new node(d);
    return a;
}
if(d>a->data){
    a->right=buildtree(a->right,d);
}
if(d<a->data){
    a->left=buildtree(a->left,d);
}
return a;
}

void inorder(node *a,int *arr,int &i){
    if(a==NULL){
        return;
    }
    inorder(a->left,arr,i);
    arr[i]=a->data;
    ++i;
    inorder(a->right,arr,i);
    return;
}



};


int main(){
node *a;
a=NULL;
int d;
while(1){
    cout<<"enter data: ";
    cin>>d;
    a=(*a).buildtree(a,d);
if(d==-1){
    break;
}
}
int i=0,arr[100],s=0;
(*a).inorder(a,arr,i);
for(int j=0;j<i-1;j++){
if(arr[j]>arr[j+1]){
    cout<<"false";
    s=1;
    break;
}
}
if(s!=1){
cout<<"true";
}

return 0;
}