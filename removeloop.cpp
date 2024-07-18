#include<iostream>
#include<iomanip>
using namespace std;
class node{
public:
int data;
node *ptr;
node(int value){
    (*this).data=value;
    (*this).ptr=this;
}
void insertathead(node *(&temp),node *athead){
(*athead).ptr=(*temp).ptr;
(*temp).ptr=athead;
}
void insertattail(node *(&temp),node *attail){
(*attail).ptr=(*temp).ptr;
(*temp).ptr=attail;
temp=attail;
}
void insertanypositionexceptheadandtail(node *(&temp),node *anyposition,int value){
node *getback=temp;
while((*temp).data!=value){
temp=(*temp).ptr;
}
node *save=(*temp).ptr;
(*temp).ptr=anyposition;
(*anyposition).ptr=save;
temp=getback;
}
};

int main(){
node *node1=new node(5);
node *athead=new node(8);
node *attail=new node(7);
node *anyposition=new node(77);
node *get1=new node(88);
node *get2=new node(6);
node *get3=new node(1);
(*node1).insertathead(node1,athead);
(*node1).insertattail(node1,attail);
(*node1).insertanypositionexceptheadandtail(node1,anyposition,5);
(*node1).insertanypositionexceptheadandtail(node1,get1,5);
(*node1).insertanypositionexceptheadandtail(node1,get2,5);
(*node1).insertanypositionexceptheadandtail(node1,get3,5);
node *save=node1;
cout<<(*node1).data<<"\t";
node1=(*node1).ptr;
while(node1!=save){
    cout<<(*node1).data<<"\t";
    node1=(*node1).ptr;
}
node1=save;
while((*node1).ptr!=save){
    node1=(*node1).ptr;
}
node *save2=node1;
node1=save;
node *cur;
for(int i=0;i<2;i++){
   node1=(*node1).ptr;
}
node *save3=node1;
node1=save2;
(*node1).ptr=save3;
node1=save;
cout<<"\n";
int s=0;
while((*node1).ptr!=NULL){
    node *check=(*node1).ptr;
     cur=node1;
    node1=save;
    while(node1!=cur){
    if(node1==check){
        s=1;
        break;
    }
    node1=(*node1).ptr;
    }
    node1=check;
if(s==1){
    break;
}
}
(*cur).ptr=NULL;
node1=save;
while(node1!=NULL){
    cout<<(*node1).data<<"\t";
    node1=(*node1).ptr;
}
return 0;
}