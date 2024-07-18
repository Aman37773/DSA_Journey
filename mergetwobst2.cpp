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


void bsttolist(node *a,node *&prev,node *&save){
    if(a==NULL){
        return;
    }
    bsttolist(a->left,prev,save);
    if(prev==NULL){
        prev=a;
        save=a;
        a->left=NULL;
    }
    else{
       a->left=prev;
        prev->right=a;
        prev=a;
    }
    bsttolist(a->right,prev,save);
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

void  mergetwolist(node *&a,node *&b,node *&save){
    while(b!=NULL){
if(b->data<a->data&&a->left==NULL){
node *temp=b->right;
b->left=NULL;
b->right=a;
a->left=b;
a=b;
b=temp;
save=a;
}

else if(b->data>a->data&&a->right==NULL){
node *temp=b->right;
a->right=b;
b->left=a;
b->right=NULL;
a=b;
b=temp;
}

else if(b->data>a->data&&b->data<a->right->data){
    node *temp=b->right;
    b->right=a->right;
    a->right->left=b;
    b->left=a;
    a->right=b;
    a=b;
    b=temp;
}
else if(b->data>a->data&&b->data>a->right->data){
    a=a->right;
}
}
}

node *desirednode(node *a,int i,int mid,int j,int prevmid){
    int m;
    if(prevmid==i){
        m=prevmid;
    while(m!=mid){
        a=a->right;
        ++m;
    }
    }

else if(prevmid==j){
    m=prevmid;
    while(m!=mid){
        a=a->left;
        --m;
    }
}
    return a;
}

node * listtobst(node *a,int i,int mid,int j,int n,int prevmid){
 if((i==mid||mid==j)&&mid!=0&&mid!=n){
return NULL;
    }  
    else if((i==mid&&mid==0)||(j==mid&&mid==n)){
        a=desirednode(a,i,mid,j,prevmid);
        a->left=NULL;
        a->right=NULL;
        return a;
    }
a=desirednode(a,i,mid,j,prevmid);
a->left=listtobst(a,i,(i+mid)/2,mid,n,mid);
a->right=listtobst(a,mid,(mid+j+1)/2,j,n,mid);
return a;
}
};





int main(){
node *a,*b;
a=NULL;b=NULL;
int n1=0,n2=0,n;
cout<<"enter data for bst 1: \n";
while(1){
    int d;
    cout<<"enter data: ";
    cin>>d;
    if(d==-1){
        break;
    }
    a=(*a).buildbst(a,d);
    ++n1;
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
    ++n2;
}

n=n1+n2;

//bst to list for first bst
node *prev=NULL,*saved;
(*a).bsttolist(a,prev,saved);
a=saved;
prev->right=NULL;

//bst to list for second bst
prev=NULL;
(*b).bsttolist(b,prev,saved);
b=saved;
prev->right=NULL;

//mergetwolist
node *save=a;
(*a).mergetwolist(a,b,save);
a=save;


a=(*a).listtobst(a,0,n/2,n-1,n-1,0);






(*a).display(a);

return 0;
}