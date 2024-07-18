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
node *binarytree(node *a){
    cout<<"enter data: ";
    int d;
    cin>>d;
a=new node(d);
if(d==-1){
  return NULL;  
}
cout<<"enter data to insert at left\n ";
(*a).left=binarytree((*a).left);
cout<<"enter data to insert at right\n ";
(*a).right=binarytree((*a).right);
return a;
}
void levelordertraversal(node *a){
queue<node *> p;
p.push(a);
p.push(NULL);
node *temp=a;
while(p.empty()==0){
  if(p.front()==NULL){
    p.pop();
    continue;
  }
cout<<(*p.front()).data<<" ";
temp=p.front();
p.pop();
if((*temp).left!=NULL){
p.push((*temp).left);
}
if((*temp).right!=NULL){
p.push((*temp).right);
}
if(p.front()==NULL){
  cout<<"\n";
  p.pop();
  p.push(NULL);
}
}
return;
}

void preorder(node *a){
  if(a==NULL){
    return;
  }
  cout<<(*a).data<<" ";
preorder((*a).left);
preorder((*a).right);
}

void inorder(node *a){
  if(a==NULL){
    return;
  }
inorder((*a).left);
cout<<(*a).data<<" ";
inorder((*a).right);
return;
}

void postorder(node *a){
  if(a==NULL){
    return;
  }
postorder((*a).left);
postorder((*a).right);
cout<<(*a).data<<" ";
return;
}

void buildtreefromlevelorder(node *&a){
  queue<node*> p;
cout<<"enter data: ";
int d;
cin>>d;
a=new node(d);
  p.push(a);
while(p.empty()==0){
  if(p.front()==NULL){
    p.pop();
    continue;
  }
node *temp=p.front();
cout<<"enter data for left of "<<(*temp).data<<": ";
cin>>d;
if(d==-1){
  (*temp).left=NULL;
}
else{
(*temp).left=new node(d);
p.push((*temp).left);
}

cout<<"enter data for right of "<<(*temp).data<<": ";
cin>>d;
if(d==-1){
  (*temp).right=NULL;
}
else{
(*temp).right=new node(d);
p.push((*temp).right);
}
p.pop();
}
}

void countleaf(node *a,int &count){
  if(a==NULL){
    return;
  }
  countleaf((*a).left,count);
countleaf((*a).right,count);
if((*a).left==NULL&&(*a).right==NULL){
++count;
}
return;
}

void reverselevelordertraversal(node *a,int *arr,int &s){
queue<node *> p;
p.push(a);
p.push(NULL);
node *temp=a;
while(p.empty()==0){
  if(p.front()==NULL){
    p.pop();
    continue;
  }
arr[s]=(*p.front()).data;
++s;
temp=p.front();
p.pop();
if((*temp).right!=NULL){
p.push((*temp).right);
}
if((*temp).left!=NULL){
p.push((*temp).left);
}
}
return;
}

};
int main(){
node *a=NULL;
int arr[100],s=0;
//a=(*a).binarytree(a);
//(*a).levelordertraversal(a);
//(*a).preorder(a);
//cout<<"\n";
//(*a).inorder(a);
//cout<<"\n";
//(*a).postorder(a);
(*a).buildtreefromlevelorder(a);
//int count=0;
//(*a).countleaf(a,count);
//cout<<count;
(*a).reverselevelordertraversal(a,arr,s);
for(int i=s-1;i>=0;i--){
  cout<<arr[i]<<" ";
}

return 0;
}