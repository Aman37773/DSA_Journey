#include<iostream>
#include<iomanip>
using namespace std;
class node{
public:
int data;
node *ptr1;
node *ptr2;
node(int value){
    (*this).data=value;
    (*this).ptr1=this;
    (*this).ptr2=this;
}
void insertathead(node *(&temp),node *(&athead)){
node *getback=temp;
node *save=(*temp).ptr2;
(*athead).ptr2=(*temp).ptr2;
(*athead).ptr1=temp;
(*temp).ptr2=athead;
temp=save;
(*temp).ptr1=athead;
temp=getback;
}
void insertattail(node *(&temp) ,node *(&attail)){
node *save=(*temp).ptr2;
(*attail).ptr2=(*temp).ptr2;
(*attail).ptr1=temp;
(*temp).ptr2=attail;
temp=save;
(*temp).ptr1=attail;
temp=attail;
}
void insertanypositionexceptheadandtail(node *(&temp),node *(&anyposition),int value){
node *getback=temp;//how this calls constructor
while((*temp).data!=value){
temp=(*temp).ptr2;
}
node *save=(*temp).ptr2;
(*anyposition).ptr2=(*temp).ptr2;
(*temp).ptr2=anyposition;
(*anyposition).ptr1=temp;
temp=save;
(*temp).ptr1=anyposition;
temp=getback;
}
void deletion(node *(&temp),int value){
    while((*temp).data!=value){
    temp= (*temp).ptr2;
    }
    node *save1=(*temp).ptr1;
    node *save2=(*temp).ptr2;
    node *save=temp;
    temp=(*temp).ptr1;
   (*temp).ptr2=save2;
   temp=save2;
   (*temp).ptr1=save1;
temp=save;
(*temp).ptr1=NULL;
(*temp).ptr2=NULL;
delete temp;
temp=save1;
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
(*node1).deletion(node1,8);
node *save=node1;
cout<<(*node1).data<<"\t";
node1=(*node1).ptr2;
while(node1!=save){
    cout<<(*node1).data<<"\t";
    node1=(*node1).ptr2;
}//gets printed from tail to tail-1
return 0;
}