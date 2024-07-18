#include<iostream>
#include<iomanip>
#include<queue>
#include<algorithm>
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
void inorder(node *a,int &sum,int &value){
    if(a==NULL){
        return;
    }
    sum=sum+(*a).data;

    inorder((*a).left,sum,value);
    inorder((*a).right,sum,value);
if((*a).left==NULL&&(*a).right==NULL){
    value=max(value,sum);
}
sum-=(*a).data;
return;
}
};

int main(){
node *a;
a=NULL;
int sum=0,value=0;
a=(*a).buildtree(a);
(*a).inorder(a,sum,value);
cout<<value;
return 0;
}