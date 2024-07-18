#include<iostream>
#include<iomanip>
using namespace std;
class node{
public: 
int data;
node *ptr;

void inserthead(int data,node *&node1){
    node *temp=new node;
    (*temp).data=data;
    (*temp).ptr=NULL;
    if(node1==NULL){
        node1=temp;
    }
    else{
        (*temp).ptr=node1;
        node1=temp;
    }
}
void insertany(int data,node *&node1,int position){
   node *temp=new node;
    (*temp).data=data;
    (*temp).ptr=NULL;
    if(node1==NULL){
        node1=temp;
    }
    else{
        node *travel=node1;
        int m=1;
        while(m!=position-1){
            travel=(*travel).ptr;
            m++;
        }
        (*temp).ptr=(*travel).ptr;
        (*travel).ptr=temp;
    } 
}
void inserttail(int data,node *&node1){
    node *temp=new node;
    (*temp).data=data;
    (*temp).ptr=NULL;
    if(node1==NULL){
        node1=temp;
    }
    else{
        node *travel=node1;
        while((*travel).ptr!=NULL){
            travel=(*travel).ptr;
        }
        (*travel).ptr=temp;
        (*temp).ptr=NULL;
    }
}
node *display(node *dis,node *&tail){
    node *check=dis;
while(dis!=NULL){
    cout<<(*dis).data<<"\t";
if((*dis).data<(*check).data){
    check=dis;
}
    tail=dis;
    dis=(*dis).ptr;
}
return check;
}

node *middle(node *head){
node *slow=head;
node *fast=head;
do{
if((*fast).ptr==NULL){
return slow;
}
else{
    fast=(*fast).ptr;
}
if((*fast).ptr==NULL){
    return slow;
}
else{
    fast=(*fast).ptr;
    slow=(*slow).ptr;
}
}
while(1);
}

void sort1(node *&head,node *tail){
if(head==tail){
    return;
}
(*tail).ptr=NULL;
node *mid=(*head).middle(head);
node *right;
right=(*mid).ptr;
(*mid).ptr=NULL;
sort1(head,mid);
sort1(right,tail);
node *headyy=head;
while(headyy!=NULL){
    if(headyy==right){
        return;
    }
    headyy=(*headyy).ptr;
}
sort(head,right);

return;
}

void sort(node *&head,node *&right){
node *heady=head;
node *righty=right;
node *headynext=(*heady).ptr;
while(heady!=NULL&&righty!=NULL){
if((*righty).data<(*heady).data){
    node *get=righty;
    righty=(*righty).ptr;
(*get).ptr=heady;
heady=get;
headynext=(*heady).ptr;
head=get;
}
else if(headynext!=NULL&&(*righty).data>=(*heady).data&&(*righty).data<=(*headynext).data){
node *get=righty;
righty=(*righty).ptr;
(*get).ptr=headynext;
(*heady).ptr=get;
heady=get;
headynext=(*heady).ptr;
}
else if((*righty).data>=(*heady).data&&headynext==NULL){
    node *get=righty;
    righty=(*righty).ptr;
    (*get).ptr=(*heady).ptr;
(*heady).ptr=get;
heady=(*heady).ptr;
}
else{
    heady=(*heady).ptr;
    headynext=(*heady).ptr;
}
}
}
};

int main(){
node *node1,*tail;
node1=NULL;
int operation,data,position;
do{
cout<<"enter operation 1-head,2-any,3-tail,4-thats it: ";
cin>>operation;
if(operation==1){
    cout<<"enter data: ";
    cin>>data;
    (*node1).inserthead(data,node1);
}
else if(operation==2){
    cout<<"enter data and position: ";
    cin>>data>>position;
    (*node1).insertany(data,node1,position);
}
else if(operation==3){
    cout<<"enter data: ";
    cin>>data;
    (*node1).inserttail(data,node1);
}
else if(operation==4){
   break;
}
}
while(1);
(*node1).display(node1,tail);
(*node1).sort1(node1,tail);
cout<<"\n";
(*node1).display(node1,tail);
return 0;
}
