#include<iostream>
#include<iomanip>
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

 void buildtree(node *&a,int data,int in[],int n){
if(a==NULL){
    a=new node(data);
    return;
}
int s=0;
for(int i=0;i<n;i++){
    if(data==in[i]){
        break;
    }
    if(in[i]==a->data){
        s=1;
        }
}
if(s==0){
buildtree((*a).left,data,in,n);
return;
}
else{
buildtree((*a).right,data,in,n);
return;
}
}

void inorder(node *a){
    if(a==NULL){
        return;
    }
    cout<<a->data<<" ";
inorder((*a).left);
inorder((*a).right);
return;
}
};

int main(){
node *a;
a=NULL;
int in[]={4,8,2,5,1,6,3,7};
int post[]={8,4,5,2,6,7,3,1};
int n=8;
a=new node(post[n-1]);
for(int i=n-2;i>=0;i--){
(*a).buildtree(a,post[i],in,n);
}
(*a).inorder(a);
return 0;
}