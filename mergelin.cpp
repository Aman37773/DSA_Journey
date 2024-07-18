#include<iostream>
#include<iomanip>
using namespace std;
class node{
public:
int data;
node *ptr;
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


void insertathead2(node *(&temp),node *athead2){
(*athead2).ptr=temp;
temp=athead2;
}
void insertattail2(node *(&temp),node *attail2){
node *save=temp;
while((*temp).ptr!=NULL){
temp=(*temp).ptr;
}
(*attail2).ptr=NULL;
(*temp).ptr=attail2;
temp=save;
}
void insertanypositionexceptheadandtail2(node *(&temp),node *anyposition2,int position){
node *getback=temp;
int i=1;
while(i+1!=position){
temp=(*temp).ptr;
i++;
}
(*anyposition2).ptr=(*temp).ptr;
(*temp).ptr=anyposition2;
temp=getback;
}
};
int main(){
node *node1=new node(5);
node *athead=new node(0);
node *attail=new node(15);
node *anyposition=new node(3);
node *give=new node(4);
node *yes=new node(12);
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
cout<<"\n";
node *node2=new node(8);
node *athead2=new node(0);
node *attail2=new node(20);
node *anyposition2=new node(2);
node *give2=new node(5);
node *yes2=new node(12);
(*node1).insertathead2(node2,athead2);
(*node1).insertattail2(node2,attail2);
(*node1).insertanypositionexceptheadandtail2(node2,anyposition2,2);
(*node1).insertanypositionexceptheadandtail2(node2,give2,3);
(*node1).insertanypositionexceptheadandtail2(node2,yes2,5);
node *save2=node2;
while(node2!=NULL){
    cout<<(*node2).data<<"\t";
    node2=(*node2).ptr;
}
node2=save2;

node *prev=node1;
node1=(*node1).ptr;
while(node1!=NULL||node2!=NULL){
if(node1==NULL){
    (*prev).ptr=node2;
    break;
}
else if(node2==NULL){
    break;
}
if((*node2).data>=(*prev).data&&(*node2).data<=(*node1).data){
    node *savedd=(*node2).ptr;
    (*node2).ptr=node1;
    (*prev).ptr=node2;
    node2=savedd;
    prev=(*prev).ptr;
}
else{
    prev=node1;
    node1=(*node1).ptr;
}
}
node1=save;
cout<<"\n";
while(node1!=NULL){
    cout<<(*node1).data<<"\t";
    node1=(*node1).ptr;
}
return 0;
}
