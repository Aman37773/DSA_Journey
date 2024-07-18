#include<iostream>
#include<iomanip>
#include<queue>
#include<map>
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
cout<<"enter data for left of "<<(*a).data<<" \n";
(*a).left=buildtree((*a).left);
cout<<"enter data for right of "<<(*a).data<<"\n ";
(*a).right=buildtree((*a).right);
return a;
}

void lefty(node *a){
if(a==NULL||((*a).left==NULL&&(*a).right==NULL)){
    return;
}
cout<<a->data<<" ";
lefty((*a).left);
return;
}

void leaf(node *a){
    if(a==NULL){
        return;
    }
    leaf((*a).left);
    leaf((*a).right);
if((*a).right==NULL&&(*a).left==NULL){
cout<<a->data<<" ";
}
return;
}

void righty(node *a,node *&temp){
if(a==NULL){
    return ;
}
righty((*a).right,temp);
if(a!=temp){
cout<<a->data<<" ";
}
return;
}

};

int main(){
node *a;
a=(*a).buildtree(a);
node *temp=a;
(*a).lefty(a);
(*a).leaf(a);
(*a).righty(a,temp);

return 0;
}