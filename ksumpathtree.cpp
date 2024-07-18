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
void inorder(node *a,int &sum,int key,int &count){
    if(a==NULL){
        return;
    }
sum=0;
inordercheck(a,sum,key,count);
    inorder((*a).left,sum,key,count);
    inorder((*a).right,sum,key,count);
return;
}

void inordercheck(node *a,int &sum,int key,int &count){
if(a==NULL){
    return;
}
sum=sum+a->data;
if(sum==key){
    ++count;
}
inordercheck((*a).left,sum,key,count);
inordercheck((*a).right,sum,key,count);
sum-=a->data;
return;
}

};

int main(){
node *a;
a=NULL;
int sum=0,count=0,key=3;
a=(*a).buildtree(a);
(*a).inorder(a,sum,key,count);
cout<<count;
return 0;
}