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
}
};
int main(){
node *node1=new node[5];
node *newnode=new node;
(*newnode).ptr=node1[2].ptr;
node1[1].ptr=newnode;
node *re=node1;
//node *temp=new node;
//(*temp).ptr=&node1[0];
//(*temp).data=9980;
//node1=temp;
//(*temp).value();
for(int i=0;i<=5;i++){
cin>>(*node1).data;
node1=(*node1).ptr;
}
node1=re;
for(int i=0;i<=5;i++){
    cout<<(*node1).data<<"\t";
    node1=(*node1).ptr;
}
return 0;
}