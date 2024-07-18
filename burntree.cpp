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
cout<<"enter data for left of "<<(*a).data<<"\n";
(*a).left=buildtree((*a).left);
cout<<"enter data for right of "<<(*a).data<<"\n";
(*a).right=buildtree((*a).right);
return a;
}

void inorder(node *a,int &count,bool &m,int key,int &s){
    if(a==NULL){
        return;
    }
    if(a->data==key){
        //call count func for left and right node
        ++count;//need to ignite fire in nodes connected to key to form chain
        county((*a).left,count);
        county((*a).right,count);
        s=1;
        return;
    }
if(s!=1){
inorder((*a).left,count,m,key,s);
m=true;
}
if(s!=1){
inorder((*a).right,count,m,key,s);
m=false;
}
if(m==true&&s==1){
    //call count for right
    ++count;
    county((*a).right,count);
}
if(m==false&&s==1){
    //call count for left
    ++count;
    county((*a).left,count);
}

return;

}

void county(node *a,int &count){
    if(a==NULL){
        return;
    }
queue<node *> t;
t.push(a);
while(t.empty()==0){
node *temp=t.front();
int s=0;
if((*temp).left){
t.push((*temp).left);
s=1;
}
if((*temp).right){
t.push((*temp).right);
s=1;
}
t.pop();
if(s==1){
++count;
}
}
return;
}


};

int main(){
node *a;
a=NULL;
a=(*a).buildtree(a);
int key=1,count=0,s=0;
bool m;
(*a).inorder(a,count,m,key,s);
cout<<count;
return 0;
}