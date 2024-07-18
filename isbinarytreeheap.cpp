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
node *binarytree(node *a,int &n){
    cout<<"enter data: ";
    int d;
    cin>>d;
a=new node(d);
if(d==-1){
  return NULL;  
}
++n;
cout<<"enter data to insert at left of  "<<a->data<<"\n" ;
(*a).left=binarytree((*a).left,n);
cout<<"enter data to insert at right of  "<<a->data<<" \n";
(*a).right=binarytree((*a).right,n);
return a;
}
bool levelordertraversal(node *a,int n){
    if(a==NULL){
        return false;
    }
queue<node *> p;
p.push(a);
node *temp=a;
--n;
while(p.empty()==0){
temp=p.front();
p.pop();
if(temp->left==NULL&&n!=0){
    return false;
}
else if((*temp).left){
p.push((*temp).left);
--n;
}
if(temp->right==NULL&&n!=0){
    return false;
}
else if((*temp).right){
p.push((*temp).right);
--n;
}
if(p.front()==NULL){
  cout<<"\n";
  p.pop();
  p.push(NULL);
}
}
return true;
}

int checkmaxheap(node *a,int &s){
if(a->left!=NULL&&a->data<checkmaxheap(a->left,s)){
    s=1;
   return a->data;
}
if(a->right!=NULL&&a->data<checkmaxheap(a->right,s)){
      s=1;
    return a->data;
  
}
return a->data;
}






};
int main(){
node *a=NULL;
int arr[100],s=0,n=0;
a=(*a).binarytree(a,n);
bool m=(*a).levelordertraversal(a,n);
if(m==true){
    (*a).checkmaxheap(a,s);
    if(s==0){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}
else{
    cout<<"no";
}

return 0;
}