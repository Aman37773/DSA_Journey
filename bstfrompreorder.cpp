#include<bits/stdc++.h>
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

void inorder(node *a){
if(a==NULL){
    return;
}
inorder((*a).left);
cout<<a->data<<" ";
inorder((*a).right);
return;
}


};


int main(){
node *a;
a=NULL;
int d,i=0,n=8;
int arr[]={7,4,2,6,10,8,11,12};
while(i<n){  
a=(*a).buildbst(a,arr[i]);
++i;
}
(*a).inorder(a);




return 0;
}