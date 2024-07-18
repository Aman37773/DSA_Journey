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
void insert(node *(&temp),node *(&newnode),int position){
temp[position-2].ptr=newnode;
(*newnode).ptr=temp[position].ptr;
}
};
int main(){
node *node1=new node[5];
node1[4].ptr=NULL;
node *newnode=new node;
(*node1).insert(node1,newnode,2);
while(node1!=NULL){
    cout<<(*node1).data<<"\t"; 
    node1=(*node1).ptr;
}
return 0;
}