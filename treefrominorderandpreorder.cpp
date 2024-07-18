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

void postorder(node *a){
    if(a==NULL){
        return;
    }
postorder((*a).left);
postorder((*a).right);
cout<<a->data<<" ";
return;
}
};

int main(){
node *a;
a=NULL;
int pre[]={1,6,7,8};
int in[]={1,6,8,7};
int n=4;
a=new node(pre[0]);
node *save=a;
for(int i=1;i<n;i++){
(*a).buildtree(a,pre[i],in,n);
a=save;
}
(*a).postorder(a);
return 0;
}