#include<iostream>
#include<iomanip>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;

node(int d){
this->data=d;
this->left=NULL;
this->right=NULL;
}

node *buildbst(node *a,int data){
if(a==NULL){
    a=new node(data);
    return a;
}
if(data>a->data){
    a->right=buildbst(a->right,data);
}
if(data<a->data){
    a->left=buildbst(a->left,data);
}
return a;
}

void inorder(node *a,int *arr,int &i){
if(a==NULL){
    return;
}
inorder((*a).left,arr,i);
arr[i]=a->data;
i++;
inorder((*a).right,arr,i);
return;
}


};


int main(){
node *a;
a=NULL;
int d,arr[100],i=0,j=0,key=1;
while(1){
    cout<<"enter data: ";
    cin>>d;
    if(d==-1){
        break;
    }
a=(*a).buildbst(a,d);
}

(*a).inorder(a,arr,i);
j=i;
i=0;
while(i!=j){
if(arr[i]+arr[j]==key){
    cout<<arr[i]<<" + "<<arr[j];
    break;
}
else if(arr[i]+arr[j]<key){
    i++;
}
else if(arr[i]+arr[j]>key){
    j--;
}
}
if(i==j){
    cout<<"no";
}



return 0;
}