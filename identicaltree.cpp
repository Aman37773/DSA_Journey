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

void inorder(node *a,int *arr,int &i){
    if(a==NULL){
        return;
    }
    arr[i]=(*a).data;
    ++i;
    inorder((*a).left,arr,i);
    inorder((*a).right,arr,i);
    return;
}

};



int main(){
node *a,*b;
int i=0,arr[100],prr[100],j=0;
a=NULL;
b=NULL;
cout<<"build tree 1\n";
a=(*a).buildtree(a);
cout<<"build tree2\n";
b=(*b).buildtree(b);
(*a).inorder(a,arr,i);
(*a).inorder(b,prr,j);
if(i!=j){
    cout<<"no";
}
else{
    for(int p=0;p<i;p++){
        if(arr[p]!=prr[p]){
            cout<<"no";
        return 0;
        }
    }
    cout<<"yes";
}

return 0;
}