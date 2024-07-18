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

void levelordertraversal(node *a,int &i,map<node*,int> &c,int &max,int &min){
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
c[(*temp).left]=c[temp]-1;
if(c[temp]-1<min){
min=c[temp]-1;
}
    }
    if((*temp).right!=NULL){
b.push((*temp).right);
c[(*temp).right]=c[temp]+1;
if(c[temp]+1>max){
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

void levelorder(node *a,node *&temp,int i,map<node*,int> c){
if(a==NULL){
    return;
}
queue<node *> m;
m.push(a);
temp=a;
node *point;
while(m.empty()==0){
    point=m.front();
if(point->left!=NULL){
    m.push(point->left);
    if(c[point->left]==i){
        temp=point->left;
    }
}
    if(point->right!=NULL){
    m.push(point->right);
    if(c[point->right]==i){
        temp=point->right;
    }
}
m.pop();
}
}
};



int main(){
node *a,*temp;
a=NULL;
int value=1,i=0,max=0,min=0;
stack<node*> m;
map<node*,int> c;
a=(*a).buildtree(a);
(*a).levelordertraversal(a,i,c,max,min);
for(int i=min;i<=max;i++){
   (*a).levelorder(a,temp,i,c);
cout<<temp->data<<" ";
}

return 0;
}