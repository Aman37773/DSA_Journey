#include<iostream>
#include<iomanip>
#include<queue>
#include<map>
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

void search(node *a,map<node*,int> c,int i){
if(a==NULL){
    return;
}
if(c[a]==i){
    cout<<(*a).data<<" ";
}
search((*a).left,c,i);
search((*a).right,c,i);
return;
}




};



int main(){
node *a;
a=NULL;
int i=0,min=0,max=0;
map<node*,int> c;
a=(*a).buildtree(a);
(*a).levelordertraversal(a,i,c,max,min);
for(int i=min;i<=max;i++){
(*a).search(a,c,i);
}



return 0;
}