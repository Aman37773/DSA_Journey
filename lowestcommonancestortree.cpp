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
void inorder(node *a,int n,int &s,queue<node *> &p){
    if(a==NULL){
        return;
    }
    if((*a).data==n){
s=1;
        return;
    }
    if(s!=1){
    inorder((*a).left,n,s,p);
    }
    if(s!=1){
    inorder((*a).right,n,s,p);
    }
    if(s==1){
        p.push(a);
    }
return;
}
};

int main(){
node *a;//all node element are unique// lowest means which we got first during return
a=NULL;
a=(*a).buildtree(a);
queue<node*> m,n,k;
int n1=4,n2=21,s=0;
(*a).inorder(a,n1,s,m);
s=0;
(*a).inorder(a,n2,s,n);
k=n;
while(m.empty()==0){
    if(m.front()->data==k.front()->data){
        cout<<m.front()->data;
        s=1;
        break;
    }
    k.pop();
    if(k.empty()==1){
        k=n;
        m.pop();
    }
}
if(s!=1){
    cout<<"no commmon ancestor";
}

return 0;
}