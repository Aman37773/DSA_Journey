#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;
class node{
    public:
int data;
node *left;
node *right;

node(int data){
this->data=data;
this->right=NULL;
this->left=NULL;
}

node *buildtree(node *a,int d){ 
if(d==-1){
    return a;
}
if(a==NULL){
    a=new node(d);
    return a;
}
if(d>a->data){
    a->right=buildtree(a->right,d);
}
if(d<a->data){
    a->left=buildtree(a->left,d);
}
return a;
}

bool validate(node *a,int min,int max){
if(a==NULL){
    return true;
}
if(a->data>max||a->data<min){
    return false;
}
bool get=validate(a->left,min,a->data); 
if(get==false){
    return false;
} 
bool got=validate(a->right,a->data,max);
if(got==false){
    return false;
}
return true;
}



};


int main(){
node *a;
a=NULL;
int d;
while(1){
    cout<<"enter data: ";
    cin>>d;
    a=(*a).buildtree(a,d);
if(d==-1){
    break;
}
}



int min=-100000,max=100000;
if((*a).validate(a,min,max)==true){
    cout<<"true";
}
else{
    cout<<"false";
}


return 0;
}