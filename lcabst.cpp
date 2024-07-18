#include<iostream>
#include<iomanip>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;

node(int d){
this->data=d;
this->left=NULL;
this->right=NULL;
}

node *buildbst(node *a,int data){
if(a==NULL){
    a=new node(data);
    return a;
}
if(data>a->data){
    a->right=buildbst(a->right,data);
}
if(data<a->data){
    a->left=buildbst(a->left,data);
}
return a;
}

void check(node *a,int n1,int n2){
if(a==NULL){
    return;
}
if((n1>a->data&&n2<a->data)||(n1<a->data&&n2>a->data)){
cout<<a->data;
return;
}
else if(n1>a->data&&n2>a->data){
    check(a->right,n1,n2);
    return;
}
else if(n1<a->data&&n2<a->data){
    check(a->left,n1,n2);
    return;
}
}



};


int main(){
node *a;
a=NULL;
int d;
while(1){
    cout<<"enter data: ";
    cin>>d;
    if(d==-1){
        break;
    }
a=(*a).buildbst(a,d);
}
int n1=6,n2=11;
(*a).check(a,n1,n2);


return 0;
}