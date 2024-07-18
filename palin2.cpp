#include<iostream>
#include<iomanip>
#include<map>
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
node *athead=new node(2);
node *attail=new node(1);
node *anyposition=new node(0);
node *give=new node(0);
node *yes=new node(0);
(*node1).insertathead(node1,athead);
(*node1).insertattail(node1,attail);
(*node1).insertanypositionexceptheadandtail(node1,anyposition,2);
(*node1).insertanypositionexceptheadandtail(node1,give,3);
(*node1).insertanypositionexceptheadandtail(node1,yes,5);
node *save=node1;
int i=0;
while(node1!=NULL){
    cout<<(*node1).data<<"\t";
    node1=(*node1).ptr;
    ++i;
}
node1=save;
int mid;
if(i%2==0){
    mid=i/2;
}
else{
    mid=i/2+1;
}
int s=1;
node *early;
while(s<=mid){
    early=node1;
    node1=(*node1).ptr;
    ++s;
}
node *prev=node1;
node1=(*node1).ptr;
(*prev).ptr=NULL;
while(node1!=NULL){
node *next=(*node1).ptr;
(*node1).ptr=prev;
prev=node1;
node1=next;
}
(*early).ptr=prev;
node1=save;

early=(*early).ptr;
node1=save;
int check=0;
while(early!=NULL){
    if((*node1).data!=(*early).data){
        check=1;
        break;
    }
    node1=(*node1).ptr;
    early=(*early).ptr;
}
cout<<"\n";
if(check==1){
    cout<<"not a palindrome";
}
else{
    cout<<"palindrome";
}

return 0;
}