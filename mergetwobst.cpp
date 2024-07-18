#include<iostream>
#include<iomanip>
#include<math.h>
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

node *buildbst(node *a,int d){
if(a==NULL){
    a=new node(d);
    return a;
}
if(a->data<d){
    a->right=buildbst(a->right,d);
}
if(a->data>d){
    a->left=buildbst(a->left,d);
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
node *a,*b;
a=NULL;b=NULL;
cout<<"enter data for bst 1: \n";
while(1){
    int d;
    cout<<"enter data: ";
    cin>>d;
    if(d==-1){
        break;
    }
    a=(*a).buildbst(a,d);
}
cout<<"enter data for bst2: \n";
while(1){
    int d;
    cout<<"enter data: ";
    cin>>d;
    if(d==-1){
        break;
    }
    b=(*b).buildbst(b,d);
}

node *arr1[100],*arr2[100],*arr3[100];
int m,n,i=0,j=0,s=0;
(*a).inorder(a,arr1,i);
m=i-1;
i=0;
(*a).inorder(b,arr2,i);
n=i-1;
i=0;
while(i<=m||j<=n){
if(i>m){
    arr3[s]=arr2[j];
    ++s;++j;
}
else if(j>n){
    arr3[s]=arr1[i];
    ++s;++i;
}

else if(arr1[i]->data<arr2[j]->data){
arr3[s]=arr1[i];
++s;++i;
}


else if(arr1[i]->data>arr2[j]->data){
arr3[s]=arr2[j];
++s;++j;
}

else if(arr1[i]->data==arr2[j]->data){
    arr3[s]=arr1[i];
    ++s;++i;
    arr3[s]=arr2[j];
    ++s;++j;
}
}
a=(*a).buildagain(arr3,0,s/2,s-1,s-1);

(*a).display(a);

return 0;
}