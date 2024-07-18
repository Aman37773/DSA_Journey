#include<iostream>
#include<iomanip>
using namespace std;
class node{
public:
int data;
node *ptr;
node *random;
node(int value){
    (*this).data=value;
    (*this).ptr=NULL;
}
void insertathead(node *(&temp),node *athead){
(*athead).ptr=temp;
temp=athead;
}
void insertattail(node *(&temp),node *attail){
node *save=temp;
while((*temp).ptr!=NULL){
temp=(*temp).ptr;
}
(*attail).ptr=NULL;
(*temp).ptr=attail;
temp=save;
}
void insertanypositionexceptheadandtail(node *(&temp),node *anyposition,int position){
node *getback=temp;
int i=1;
while(i+1!=position){
temp=(*temp).ptr;
i++;
}
(*anyposition).ptr=(*temp).ptr;
(*temp).ptr=anyposition;
temp=getback;
}

void head(node *(&temp),node *athead){
(*athead).ptr=temp;
temp=athead;
}
};
int main(){
node *node1=new node(0);
node *athead=new node(10);
node *attail=new node(5);
node *anyposition=new node(9);
node *give=new node(6);
node *yes=new node(2);
node *name=node1;
(*node1).insertathead(node1,athead);
(*node1).insertattail(node1,attail);
(*node1).insertanypositionexceptheadandtail(node1,anyposition,2);
(*node1).insertanypositionexceptheadandtail(node1,give,3);
(*node1).insertanypositionexceptheadandtail(node1,yes,5);
node *save=node1;
while(node1!=NULL){
    cout<<(*node1).data<<"\t";
    node1=(*node1).ptr;
}
node1=save;

//random address of node1
(*node1).random=give;
node1=(*node1).ptr;

(*node1).random=name;
node1=(*node1).ptr;

(*node1).random=attail;
node1=(*node1).ptr;

(*node1).random=yes;
node1=(*node1).ptr;

(*node1).random=attail;
node1=(*node1).ptr;

(*node1).random=athead;
node1=(*node1).ptr;

node1=save;
node *node2=new node(0);
node *head;
while((*node1).ptr!=NULL){
    head=new node(0);
    (*node2).head(node2,head);
    node1=(*node1).ptr;
}
node1=save;
node *save2=node2;
while(node1!=NULL){
(*node2).data=(*node1).data;
node1=(*node1).ptr;
node2=(*node2).ptr;
}
node2=save2;
node1=save;
while(node1!=NULL){
    node *cur=node1;
    node1=(*node1).random;
    int value=(*node1).data;
    node1=cur;
    node *node2save=node2;
    node2=save2;
    while((*node2).data!=value){
        node2=(*node2).ptr;
    }
node *node2savedd=node2;
node2=node2save;
(*node2).random=node2savedd;
node2=(*node2).ptr;
node1=(*node1).ptr;
}
node1=save;
node2=save2;
cout<<"\n";
while(node2!=NULL){
node *back=node1;
node1=(*node1).random;
cout<<(*node1).data<<"\t";
node1=back;
node1=(*node1).ptr;
}
return 0;
}