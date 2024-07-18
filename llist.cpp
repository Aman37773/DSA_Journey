#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
class node{
public:
int data;
node *ptr;
node(){
(*this).ptr=(this+1);
cin>>(*this).data;
}
};
int main(){
node *node1=new node[5];
node1[4].ptr=NULL;
node *newnode=new node;
(*newnode).ptr=&node1[2];
node1[1].ptr=newnode;
while(node1!=NULL){
    cout<<(*node1).data<<"\t"; 
    node1=(*node1).ptr;
}
return 0;
}