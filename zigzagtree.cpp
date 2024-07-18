#include<iostream>
#include<iomanip>
#include<queue>
#include<stack>
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

void zigzagtraversal(node *a,int m){
if(a==NULL){
    return;
}
queue<node *> b;
b.push(a);
b.push(NULL);
node *temp=b.front();
cout<<temp->data<<" ";
++m;
while(b.empty()==0){
if(b.front()==NULL){
    b.pop();
    continue;
}
temp=b.front();
if(m%2==0){
if((*temp).right!=NULL){
    b.push((*temp).right);
    cout<<(*(*temp).right).data<<" ";
}
if((*temp).left!=NULL){
    b.push((*temp).left);
     cout<<(*(*temp).left).data<<" ";
}
}
else{
if((*temp).left!=NULL){
    b.push((*temp).left);
    cout<<temp->left->data<<" ";
}
if((*temp).right!=NULL){
    b.push((*temp).right);
   cout<<temp->right->data<<" ";
}
}
b.pop();
if(b.front()==NULL){
    b.pop();
    b.push(NULL);
reverse(b);
    ++m;
}
}
}

void reverse(queue<node*> &b){
    stack<node*> a;
while(b.front()!=NULL){
a.push(b.front());
b.pop();
}
b.pop();
while(a.empty()==0){
    b.push(a.top());
    a.pop();
}
b.push(NULL);
return;
}

};

int main(){
node *a;
int m=1;
a=NULL;
a=(*a).buildtree(a);
(*a).zigzagtraversal(a,m);
return 0;
}