#include<iostream>
#include<iomanip>
#include<queue>
#include<map>
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

void levelordertraversal(node *a,int &i,map<node*,int> &c,int &max){
    if(a==NULL){
        return;
    }
queue<node*> b;
b.push(a);
b.push(NULL);
c[a]=i;
node *temp=b.front();
while(b.empty()==0){
    if(b.front()==NULL){
        b.pop();
        continue;
    }
    temp=b.front();
    if((*temp).left!=NULL){
b.push((*temp).left);
c[(*temp).left]=c[temp]+1;
if(max<c[temp]+1){
    max=c[temp]+1;
}
    }
    if((*temp).right!=NULL){
b.push((*temp).right);
c[(*temp).right]=c[temp]+1;
if(max<c[temp]+1){
    max=c[temp]+1;
}
    }
    b.pop();
    if(b.front()==NULL){
        b.pop();
        b.push(NULL);
    }
}
return;
}

void inorder(node *a,map<node*,int> c,int i,int &s){
if(a==NULL){
    return;
}
if(c[a]==i&&s!=1){
    cout<<(*a).data<<" ";
    s=1;
}
inorder((*a).left,c,i,s);
inorder((*a).right,c,i,s);
return;
}

};



int main(){
node *a;
a=NULL;
int i=0,max=0,s=0;
map<node*,int> c;
a=(*a).buildtree(a);
(*a).levelordertraversal(a,i,c,max);
for(int i=0;i<=max;i++){
    s=0;
    (*a).inorder(a,c,i,s);
}

return 0;
}