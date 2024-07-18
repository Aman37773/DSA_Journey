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
node *value(node *&node1,int k,int s){
    if(node1==NULL){
        return NULL;
    }
node *next=(*node1).ptr;
(*node1).ptr=NULL;
node *prev=node1;
for(int i=0;i<k-1;i++){//k=2
node1=next;
next=(*node1).ptr;
(*node1).ptr=prev;
prev=node1;
}
node *save=next;
while((*node1).ptr!=NULL){
    node1=(*node1).ptr;
}
(*node1).ptr=value(save,k,s);
return prev;
}
};
int main(){
node *node1=new node(5);
node *athead=new node(8);
node *attail=new node(7);
node *anyposition=new node(77);
node *give=new node(65);
node *yes=new node(90);
(*node1).insertathead(node1,athead);
(*node1).insertattail(node1,attail);
(*node1).insertanypositionexceptheadandtail(node1,anyposition,2);
(*node1).insertanypositionexceptheadandtail(node1,give,2);
(*node1).insertanypositionexceptheadandtail(node1,yes,2);
node *save=node1;
int m=1;
while(node1!=NULL){
    cout<<(*node1).data<<"\t";
    node1=(*node1).ptr;
    m++;
}
node1=save;
int k,s;
cout<<endl<<"enter k: ";
cin>>k;
s=m/k;
node *got=(*node1).value(node1,k,s);
node1=got;
while(node1!=NULL){
    cout<<(*node1).data<<"\t";
    node1=(*node1).ptr;
}
return 0;
}