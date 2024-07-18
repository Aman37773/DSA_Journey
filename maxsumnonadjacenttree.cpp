#include<iostream>
#include<iomanip>
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

pair<int,int> inorder(node* a){
    if(a==NULL){
        pair<int,int> m(0,0);
        return m;
}
pair<int,int> lefty=inorder(a->left);
pair<int,int> righty=inorder(a->right);
pair<int,int> res;
res.first=a->data+lefty.second+righty.second;
res.second=max(lefty.first,lefty.second)+max(righty.first,righty.second);
return res;
}
};

int main(){
node *a;
a=NULL;
a=(*a).buildtree(a);
pair<int,int> get=(*a).inorder(a);
cout<<max(get.first,get.second);

return 0;
}