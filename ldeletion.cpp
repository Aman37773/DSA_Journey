#include<iostream>
#include<iomanip>
using namespace std;
class node{
public:
int data;
node *ptr;
node(){
(*this).ptr=(this+1);
cin>>(*this).data;
}
int deletion(node *(&temp),int position){
if(position==1){
temp[0].ptr=NULL;
delete &temp[0];
temp=&temp[1];
}
else{
temp[position-2].ptr=temp[position-1].ptr;
temp[position-1].ptr=NULL;
delete &temp[position-1];
}
}
~node(){
    int value=(*this).data;
    cout<<value<<" got deleted"<<endl;
}
};
int main(){
node *node1=new node[5];
node1[4].ptr=NULL;
(*node1).deletion(node1,5);
while(node1!=NULL){
cout<<(*node1).data<<"\t"; 
node1=(*node1).ptr;
}
return 0;
}