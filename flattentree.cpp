#include<iostream>
#include<iomanip>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
node(int data){
(*this).data=data;
(*this).left=NULL;
(*this).right=NULL;
}


node *buildtree(node *a){
cout<<"enter data: ";
int d;
cin>>d;
a=new node(d);
if(d==-1){
    return NULL;
}
cout<<"enter data for left of "<<(*a).data<<"\n";
(*a).left=buildtree((*a).left);
cout<<"enter data for right of "<<(*a).data<<"\n";
(*a).right=buildtree((*a).right);
return a;
}

void morristraversal(node *a){
    node *cur=a;
    while(cur!=NULL){
if((*cur).left==NULL){
cur=cur->right;
}
else{
node *temp=cur->left;
predecessor(cur,temp)->right=cur->right;
cur->right=cur->left;
cur=cur->left;
}
    }
}

node* predecessor(node *cur,node *temp){
    while(temp->right!=NULL&&temp->right!=cur){
temp=(*temp).right;
    }
return temp;
}

void display(node *a){
    if(a==NULL){
        return;
    }
    cout<<a->data<<" ";
    display((*a).right);
    return;
}

};

int main(){
node *a;
a=NULL;
a=(*a).buildtree(a);
(*a).morristraversal(a);
(*a).display(a);
return 0;
}