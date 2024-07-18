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
node *node1=new node(3);
node *athead=new node(1);
node *attail=new node(19);
node *anyposition=new node(3);
node *give=new node(3);
node *yes=new node(4);
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
while(node1!=NULL){
node *save2=node1;
node1=(*node1).ptr;
if(node1==NULL){
break;
}
while((*node1).data==(*save2).data){
    (*save2).ptr=(*node1).ptr;
    (*node1).ptr=NULL;
    delete node1;
    node1=(*save2).ptr;
    if(node1==NULL){
        break;
    }
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
//null check is very important
//null check is very important
//null check is very important
//null check is very important