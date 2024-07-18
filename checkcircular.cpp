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
    (*this).ptr=this;
}
void insertathead(node *(&temp),node *(&athead)){
(*athead).ptr=(*temp).ptr;
(*temp).ptr=athead;
}
void insertattail(node *(&temp),node *(&attail)){
(*attail).ptr=(*temp).ptr;
(*temp).ptr=attail;
temp=attail;
}
void insertanypositionexceptheadandtail(node *(&temp),node *(&anyposition),int value){
node *getback=temp;
while((*temp).data!=value){
temp=(*temp).ptr;
}
node *save=(*temp).ptr;
(*temp).ptr=anyposition;
(*anyposition).ptr=save;
temp=getback;
}
void deletion(node *(&temp),int value){
    while((*temp).data!=value){
    temp= (*temp).ptr;
    }
    node *save1=(*temp).ptr;
    node *save2=temp;
    while((*temp).ptr!=save2){
        temp=(*temp).ptr;
    }
    node *save3=temp;
    temp=(*temp).ptr;
   (*temp).ptr=NULL;
    delete temp;
temp=save3;
(*temp).ptr=save1;
}
~node(){
    int value=(*this).data;
    cout<<value<<" got deleted"<<endl;
}
};

int main(){
node *node1=new node(5);
node *athead=new node(8);
node *attail=new node(7);
node *anyposition=new node(77);
(*node1).insertathead(node1,athead);
(*node1).insertattail(node1,attail);
(*node1).insertanypositionexceptheadandtail(node1,anyposition,5);
(*node1).deletion(node1,7);
node *save=node1;
int s=0;
while(node1!=save){
    node1=(*node1).ptr;
    if(node1==NULL){
        s=1;
        break;
    }
}
if(s==1){
    cout<<"no";
}
else{
    cout<<"yes";
}
return 0;
}