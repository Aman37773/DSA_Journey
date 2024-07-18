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

void inorder(node *a,node * *b,int &i){
if(a==NULL){
    return;
}
inorder((*a).left,b,i);
b[i]=a;
i++;
inorder((*a).right,b,i);
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

node* buildagain(node* *b,int i,int mid,int j,int n){
    if((i==mid||mid==j)&&mid!=0&&mid!=n){
return NULL;
    }  
    else if((i==mid&&mid==0)||(j==mid&&mid==n)){
        b[mid]->left=NULL;
        b[mid]->right=NULL;
        return b[mid];
    }

b[mid]->left=buildagain(b,i,(i+mid)/2,mid,n);
b[mid]->right=buildagain(b,mid,(mid+j+1)/2,j,n);
return b[mid];
}
};




int main(){
node *a;
a=NULL;
int d,i=0,j=0,mid,n;
node* b[100];
while(1){
    cout<<"enter data: ";
    cin>>d;
    if(d==-1){
        break;
    }
a=(*a).buildbst(a,d);
}
(*a).inorder(a,b,i);


(*a).display(a);
cout<<"\n";

j=i-1;
n=i-1;
mid=i/2;
i=0;

a=(*a).buildagain(b,i,mid,j,n);

(*a).display(a);

return 0;
}