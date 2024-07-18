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

int height(node *a,int &count){
    if(a==NULL){
        return count;
    }
queue<node*> b;
b.push(a);
b.push(NULL);
node *temp=b.front();
while(b.empty()==0){
    if(b.front()==NULL){
        b.pop();
        continue;
    }
    temp=b.front();
    if((*temp).left!=NULL){
b.push((*temp).left);
    }
    if((*temp).right!=NULL){
b.push((*temp).right);
    }
    b.pop();
    if(b.front()==NULL){
        ++count;
        b.pop();
        b.push(NULL);
    }
}
return count;
}

int inorder(node *a,int count){
    if(a==NULL){
        return 1;
    }
count=0;
int val1=height((*a).left,count);
count=0;
int val2=height((*a).right,count);
    if(val1-val2<-1||val1-val2>1){
        return -1;
    }
    int get=inorder((*a).left,count);
    int got=inorder((*a).right,count);
    if(get==1&&got==1){
    return 1;
}
else{
    return -1;
}
}


};



int main(){
node *a;
int count=0;
a=NULL;
a=(*a).buildtree(a);
int get=(*a).inorder(a,count);
if(get==1){
    cout<<"balanced";
}
else{
    cout<<"unbalanced";
}

return 0;
}