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

void levelordertraversal(node *a,queue<node*> &ans){
    if(a==NULL){
        return;
    }
queue<node*> b;
b.push(a);
node *temp;
while(b.empty()==0){
    temp=b.front();
while(temp!=NULL){
  ans.push(temp);
  if((*temp).left!=NULL){
    b.push((*temp).left);
  }
  temp=(*temp).right;  
}
b.pop();    
}
return;
}

};



int main(){
node *a;
a=NULL;
queue<node*> ans;
a=(*a).buildtree(a);
(*a).levelordertraversal(a,ans);
while(ans.empty()==0){
    cout<<(*ans.front()).data<<" ";
    ans.pop();
}

return 0;
}