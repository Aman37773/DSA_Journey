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
void insertathead(node *(&temp),node *(&athead)){
(*athead).ptr=temp;
temp=athead;
}
void insertattail(node *(&temp),node *(&attail)){
node *save=temp;
while((*temp).ptr!=NULL){
temp=(*temp).ptr;
}
(*attail).ptr=NULL;
(*temp).ptr=attail;
temp=save;
}
void insertanypositionexceptheadandtail(node *(&temp),node *(&anyposition),int position){
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
node *node1=new node(5);
node *athead=new node(8);
node *attail=new node(7);
node *anyposition=new node(77);
node *hello=new node(0);
(*node1).insertathead(node1,athead);
(*node1).insertattail(node1,attail);
(*node1).insertanypositionexceptheadandtail(node1,anyposition,2);
(*node1).insertanypositionexceptheadandtail(node1,hello,2);
node *save=node1;
int m=0,s=0;;
while(node1!=NULL){
    cout<<(*node1).data<<"\t";
    node1=(*node1).ptr;
    m++;
}
cout<<"\n";
node1=save;
if(m%2==0){
    s=1;
    int i=1;
    m=m/2;
    while(i!=m){
    node1=(*node1).ptr;
    i++;
    }
}
else{
    int i=1;
    m=m/2+1;
    while(i!=m){
        node1=(*node1).ptr;
        i++;
    }
}
if(s==1){
    cout<<(*node1).data<<"\t";
     node1=(*node1).ptr;
cout<<(*node1).data;
}
else{
    cout<<(*node1).data;
   
}
return 0;
}