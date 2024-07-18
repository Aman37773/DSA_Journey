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
node *athead=new node(0);
node *attail=new node(2);
node *anyposition=new node(1);
node *give=new node(0);
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
map<int,int> m;
for(int i=0;i<=2;i++){
     m[i]=0;
while(node1!=NULL){
if((*node1).data==i){
    m[i]++;
}
node1=(*node1).ptr;
}
node1=save;
}
int count=0;
for(int i=0;i<=2;i++){
    while(count!=m[i]){
        (*node1).data=i;
        node1=(*node1).ptr;
        count++;
    }
    count=0;
}
node1=save;
cout<<"\n";
while(node1!=NULL){
    cout<<(*node1).data<<"\t";
    node1=(*node1).ptr;
}
return 0;
}
