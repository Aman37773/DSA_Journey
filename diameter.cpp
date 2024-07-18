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

int height(node *a,int &count){
    if(a==NULL){
        return count;
    }
queue<node*> p;
p.push(a);
p.push(NULL);
while(p.empty()==0){
    if(p.front()==NULL){
        p.pop();
        continue;
    }
node *temp=p.front();
if((*temp).left!=NULL){
p.push((*temp).left);
}
if((*temp).right!=NULL){
p.push((*temp).right);
}
p.pop();
if(p.front()==NULL){
    p.pop();
++count;
p.push(NULL);
    }
}
return count;
}



};



int main(){
node *a;
a=NULL;
a=(*a).buildtree(a);
int count=0;
cout<<(*a).height(a,count);


return 0;
}