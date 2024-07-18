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

bool validate(node *a,int min,int maxy){
if(a==NULL){
    return true;
}
if(a->data>maxy||a->data<min){
    return false;
}
bool get=validate(a->left,min,a->data); 
if(get==false){
    return false;
} 
bool got=validate(a->right,a->data,maxy);
if(got==false){
    return false;
}
return true;
}

void inorder(node *a,int &highest){
if(a==NULL){
    return;
}

int min=-100000,maxy=100000;
if(validate(a,min,maxy)==true){
    int t=height(a);
   highest=max(highest,t);
}

inorder(a->left,highest);
inorder(a->right,highest);
return;
}

int height(node *a){
    if(a==NULL){
       return 0; 
    }
int m=0;
queue<node *> p;
p.push(a);
p.push(NULL);
while(p.empty()==0){
if(p.front()==NULL){
    p.pop();
    continue;
}
node *temp=p.front();
if(temp->left){
    p.push(temp->left);
}
if(temp->right){
    p.push(temp->right);
}
p.pop();
if(p.front()==NULL){
    ++m;
    p.push(NULL);
    p.pop();
}
}
return m;
}





};


int main(){
node *a;
a=NULL;
int d,highest=1;
a=(*a).buildtree(a);
(*a).inorder(a,highest);
cout<<highest;

return 0;
}