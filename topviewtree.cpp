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

void levelordertraversal(node *a,int &i,map<node*,int> &c){
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
    }
    if((*temp).right!=NULL){
b.push((*temp).right);
c[(*temp).right]=c[temp]+1;
    }
    b.pop();
    if(b.front()==NULL){
        b.pop();
        b.push(NULL);
    }
}
return;
}

void lefty(node *a,map<node*,int> c,int &value,stack<node*> &m){
if(a==NULL){
    return;
}
if(c[a]<value){
m.push(a);
value=c[a];
}
lefty((*a).left,c,value,m);
lefty((*a).right,c,value,m);
return;
}

void righty(node *a,map<node*,int> c,int &value){
if(a==NULL){
    return;
}
if(c[a]>value){
    cout<<(*a).data<<" ";
value=c[a];
}
righty((*a).right,c,value);
righty((*a).left,c,value);
return;


}

};



int main(){
node *a;
a=NULL;
int value=1,i=0;
stack<node*> m;
map<node*,int> c;
a=(*a).buildtree(a);
(*a).levelordertraversal(a,i,c);
(*a).lefty(a,c,value,m);
while(m.empty()==0){
    cout<<(*m.top()).data<<" ";
    m.pop();
}
value=0;
(*a).righty(a,c,value);

return 0;
}