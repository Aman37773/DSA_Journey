#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
class node{
public:
int data;
node *ptr1;
node *ptr2;
node(int value){
(*this).ptr1=NULL;
(*this).ptr2=NULL;
(*this).data=value;
}
void insertathead(node *(&temp),node *(&newnode)){
(*newnode).ptr1=NULL;
(*newnode).ptr2=temp;
(*temp).ptr1=newnode;
temp=newnode;
}
void insertattail(node *(&temp),node *(&newnode)){
node *getback=temp;
    while((*temp).ptr2!=NULL){
        temp=(*temp).ptr2;
    }
(*temp).ptr2=newnode;
(*newnode).ptr1=temp;
(*newnode).ptr2=NULL;
temp=getback;
}
void insertanypositionexceptheadandtail(node *(&temp),node *(&newnode),int position){
int i=1;
node *getback=temp;
while(position!=i){
    temp=(*temp).ptr2;
    i++;
}
(*newnode).ptr2=temp;
(*newnode).ptr1=(*temp).ptr1;
(*temp).ptr1=newnode;
temp=(*newnode).ptr1;
(*temp).ptr2=newnode;
temp=getback;
}
};
int main(){
node *doblin=new node(5);
node *athead=new node(90);
node *attail=new node(6);
node *anyposition=new node(57);
node *middle=new node(0);
(*doblin).insertathead(doblin,athead);
(*doblin).insertattail(doblin,attail);
(*doblin).insertanypositionexceptheadandtail(doblin,anyposition,2);
(*doblin).insertanypositionexceptheadandtail(doblin,middle,3);
while(doblin!=NULL){
    cout<<(*doblin).data<<"\t";
    doblin=(*doblin).ptr2;
}
return 0;
}