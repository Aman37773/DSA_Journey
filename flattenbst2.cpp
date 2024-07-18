#include<bits/stdc++.h>
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

node *buildtree(node *a){ 
int d;
cout<<"enter data: ";
cin>>d;
if(d==-1){
    return NULL;
}
a=new node(d);
cout<<"enter data for left of "<<a->data<<": \n";
a->left=buildtree(a);
cout<<"enter data for right of "<<a->data<<": \n";
a->right=buildtree(a);
return a;
}

void inorder(node *a,node *&prev,node *&save){
    if(a==NULL){
        return;
    }
    inorder(a->left,prev,save);
    if(prev==NULL){
        prev=a;
        save=a;
    }
    else{
        prev->left=NULL;
        prev->right=a;
        prev=a;
    }
    inorder(a->right,prev,save);
    return;
}


void display(node *a){
    if(a==NULL){
        return;
    }
    cout<<a->data<<" ";
    display(a->right);
return;
}





};


int main(){
node *a;
a=NULL;
a=(*a).buildtree(a);
node *prev=NULL,*save;
(*a).inorder(a,prev,save);
a=save;
(*a).display(a);
return 0;
}