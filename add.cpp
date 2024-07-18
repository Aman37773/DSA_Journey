#include<iostream>
#include<iomanip>
#include<math.h>
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
void insertatheadnew(node *(&temp),node *athead){
(*athead).ptr=temp;
temp=athead;
}
};
int main(){
node *node1=new node(5);
node *athead=new node(0);
node *attail=new node(1);
node *anyposition=new node(3);
node *give=new node(4);
node *yes=new node(1);
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
node *attail2=new node(2);
node *anyposition2=new node(2);
node *give2=new node(5);
node *yes2=new node(1);
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

int value1=0;
while(node1!=NULL){
int got=(*node1).data;
int power=0;
if(got==0){
    power=1;
}
while(got!=0){
    got=got/10;
    ++power;
}
value1=value1*pow(10,power)+(*node1).data;
node1=(*node1).ptr;
}
int value2=0;
while(node2!=NULL){
    int got=(*node2).data;
int power=0;
if(got==0){
    power=1;
}
while(got!=0){
    got=got/10;
    ++power;
}
value2=value2*pow(10,power)+(*node2).data;
node2=(*node2).ptr;
}

cout<<endl<<value1<<endl;
cout<<endl<<value2<<endl;
int netvalue=value1+value2;
cout<<endl<<netvalue<<endl;

int nodalvalue=netvalue%10;
netvalue=netvalue/10;
node *newone=new node(nodalvalue);
while(netvalue!=0){
nodalvalue=netvalue%10;
netvalue=netvalue/10;
node *newhead=new node(nodalvalue);
(*newone).insertatheadnew(newone,newhead);
}
while(newone!=NULL){
    cout<<(*newone).data<<"\t";
    newone=(*newone).ptr;
}
return 0;
}
