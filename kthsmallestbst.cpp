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

void inorder(node *a,int k,int &m){
    if(a==NULL){
        return;
    }
    inorder(a->left,k,m);
    ++m;
    if(m==k){
        cout<<a->data;
        return;
    }
    inorder(a->right,k,m);
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
    if(d==-1){
        break;
    }
a=(*a).buildbst(a,d);
}

int k=9,m=0;
(*a).inorder(a,k,m);



return 0;
}