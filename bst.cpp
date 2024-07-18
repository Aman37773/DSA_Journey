#include<iostream>
#include<iomanip>
using namespace std;//left are srictly smaller than root(applicablr to right too)
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

node *buildtree(node *a,int d){ //insertion complexity is 0(n) in bst
if(d==-1){
    return a;
}
if(a==NULL){
    a=new node(d);
    return a;
}
if(d>a->data){
    a->right=buildtree(a->right,d);
}
if(d<a->data){
    a->left=buildtree(a->left,d);
}
return a;
}

void inorder(node *a){
    if(a==NULL){
        return;
    }
    cout<<a->data<<" ";
    inorder(a->left);
    inorder(a->right);
    return;
}

void search(node *a,bool &m,int key){
    if(a==NULL){
        m=false;
        return;
    }
  if(a->data==key){
    m=true;
    return;
  }
  if(key<a->data){
    search(a->left,m,key);
    return;
  }
  if(key>a->data){
    search(a->right,m,key);
    return;
}
}

node *maxy(node *a){
    if(a->right==NULL){
    return a;
    }
   node *m=maxy(a->right);
return m;
}

node *miny(node *a){
    if(a->left==NULL){
    return a;
    }
   node *m=miny(a->left);
return m;
}

node *deleted(node *a,int key){  //deletion complexity is 0(n) in bst
if(a->data==key){
    //0 child
if(a->left==NULL&&a->right==NULL){
    delete a;
return NULL;
}
//1 child
    if(a->right==NULL&&a->left!=NULL){
    node *temp=a->left;
a->left=NULL;
delete a;
return temp;
}
 if(a->left==NULL&&a->right!=NULL){
    node *temp=a->right;
a->right=NULL;
delete a;
return temp;
}
//2 child
if(a->right!=NULL&&a->left!=NULL){
node *temp=maxy(a->left);
a->data=temp->data;
a->left=deleted(a->left,temp->data);
return a;
}

}
if(a->data<key){
   a->right = deleted(a->right,key);
    return a;
}
if(a->data>key){
  a->left =  deleted(a->left,key);
    return a;
}
}

void inorderpredecessor(node *a,int key,int &s,node *&temp){ //just smaler element than key
    if(a==NULL){
        return;
    }
    inorderpredecessor(a->left,key,s,temp);
   if(a->data==key&&s!=1){
    if(temp){
    cout<<temp->data<<" ";
    }
    s=1;
   }
temp=a;
    inorderpredecessor(a->right,key,s,temp);
return;
}

void inordersuccessor(node *a,int key,int &s){// just greater element than key
    if(a==NULL){
        return;
    }
    inordersuccessor(a->left,key,s);
    if(s==1){
        cout<<a->data<<" ";
        s=0;
    }
    if(a->data==key){
        s=1;
    }
    inordersuccessor(a->right,key,s);
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
    a=(*a).buildtree(a,d);
if(d==-1){
    break;
}
}
//(*a).inorder(a);

//int key=1;
//bool m;
//(*a).search(a,m,key);
//if(m==1){
 //   cout<<"true";
//}
//else{
 //   cout<<"false";
//}

//cout<<(*a).maxy(a)->data<<" ";
//cout<<(*a).miny(a)->data<<" ";

//what is inorder predeccesor and inorder successor?
int key=11,s=0;
node *temp=NULL;
(*a).inorderpredecessor(a,key,s,temp);
s=0;
(*a).inordersuccessor(a,key,s);



//int key=21;
//(*a).deleted(a,key);
//(*a).inorder(a);

return 0;
}