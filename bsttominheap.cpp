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
cout<<"enter data to insert at left of  "<<a->data<<"\n" ;
(*a).left=binarytree((*a).left);
cout<<"enter data to insert at right of  "<<a->data<<" \n";
(*a).right=binarytree((*a).right);
return a;
}

void inorder(node *a,int *arr,int &i){
if(a==NULL){
    return;
}
inorder(a->left,arr,i);
arr[i]=a->data;
++i;
inorder(a->right,arr,i);
return;
}

void insertagain(node *a,int *arr,int &i){
    if(a==NULL){
        return;
    }
a->data=arr[i];
++i;
insertagain(a->left,arr,i);
insertagain(a->right,arr,i);
return;
}



void display(node *a){
if(a==NULL){
    return;
}
cout<<a->data<<" ";
display(a->left);
display(a->right);
return;
}


};
int main(){
node *a=NULL;
a=(*a).binarytree(a);
int arr[100],i=0;
(*a).inorder(a,arr,i);
i=0;
(*a).insertagain(a,arr,i);
(*a).display(a);
return 0;
}