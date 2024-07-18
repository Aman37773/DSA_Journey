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

void inorder(node *a,int &value,int &count,int &maximum){
    if(a==NULL){
        return;
    }
count=0;
value=height((*a).left,count);
count=0;
value=value+height((*a).right,count)+1;
maximum=max(maximum,value);
    inorder((*a).left,value,count,maximum);
    inorder((*a).right,value,count,maximum);
    return;
}



};



int main(){
node *a;
int value=0,maximum=0,count=0;
a=NULL;
a=(*a).buildtree(a);
(*a).inorder(a,value,count,maximum);
cout<<maximum;

return 0;
}