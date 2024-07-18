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
void inorder(node *a,int key,int k,int &m,int &s){
    if(a==NULL){
        return;
    }
    if(a->data==key){
        s=1;
        return;
    }
    if(s!=1){
    inorder((*a).left,key,k,m,s);
    }
    if(s!=1){
    inorder((*a).right,key,k,m,s);
    }
if(s==1){
    ++m;
    if(m==k){
        cout<<a->data;
    }
}
return;
}


};

int main(){
node *a;
a=NULL;
int key=3,k=1,m=0,s=0;
a=(*a).buildtree(a);
(*a).inorder(a,key,k,m,s);
return 0;
}