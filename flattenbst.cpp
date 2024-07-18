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

void inorder(node *a,list<node*> &b){
if(a==NULL){
    return;
}
inorder((*a).left,b);
b.push_back(a);
inorder((*a).right,b);
return;
}

void display(node *a){
    if(a==NULL){
        return;
    }
    cout<<a->data<<" ";
    display((*a).right);
}

};


int main(){
node *a;
a=NULL;
int d,i=0,j=0;
list<node*> b;
while(1){
    cout<<"enter data: ";
    cin>>d;
    if(d==-1){
        break;
    }
a=(*a).buildbst(a,d);
}
(*a).inorder(a,b);
a=b.front();
while(b.empty()==0){
    node *temp=b.front();
    b.pop_front();
    temp->left=NULL;
    if(b.empty()==0){
    temp->right=b.front();
    }
    else{
        temp->right=NULL;
    }

}
(*a).display(a);

return 0;
}