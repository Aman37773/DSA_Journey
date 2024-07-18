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
};
int main(){
node *node1=new node(0);
node *athead=new node(1);
node *attail=new node(0);
node *anyposition=new node(1);
node *give=new node(2);
node *yes=new node(2);
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
for(int i=0;i<=2;i++){
    while((*node1).data!=i){
    node1=(*node1).ptr;
}
node *prev=node1;
node *justprev=node1;
    while(node1!=NULL){
        justprev=node1;
        node1=(*node1).ptr;
        if(node1==NULL){
            break;
        }
        if((*node1).data==i&&(*justprev).data!=i){
            (*justprev).ptr=(*node1).ptr;
            (*node1).ptr=(*prev).ptr;
            (*prev).ptr=node1;
        prev=node1;
        }
    }
    node1=save;
}
cout<<"\n";
while((*node1).data!=0){
    node1=(*node1).ptr;
}
node *firstzero=node1;
node *earlier;
while((*node1).data==0){
  earlier=node1;
    node1=(*node1).ptr;
    if(node1==NULL){
        break;
    }
}
node *lastzero=earlier;

node1=save;
while((*node1).data!=1){
    node1=(*node1).ptr;
}
node *firstone=node1;
while((*node1).data==1){
    earlier=node1;
    node1=(*node1).ptr;
    if(node1==NULL){
        break;
    }
}
node *lastone=earlier;

node1=save;
while((*node1).data!=2){
    node1=(*node1).ptr;
}
node *firsttwo=node1;
while((*node1).data==2){
    earlier=node1;
    node1=(*node1).ptr;
    if(node1==NULL){
        break;
    }
}
node *lasttwo=earlier;

(*lastzero).ptr=firstone;
(*lastone).ptr=firsttwo;
(*lasttwo).ptr=NULL;

node1=firstzero;
while(node1!=NULL){
    cout<<(*node1).data<<"\t";
    node1=(*node1).ptr;
}
return 0;
}