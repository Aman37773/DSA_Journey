#include<iostream>
#include<iomanip>
using namespace std;

class node{
public: 
int data;
node *ptr;
void push(int data,node *&a,int &s,node *&back){
node *temp=new node;
(*temp).data=data;
(*temp).ptr=NULL;
if(this==NULL){
    back=temp;
   a=temp; 
   ++s;
}
else{
(*this).ptr=temp;
a=temp;
++s;
}
}
void pop(node *&back){
    if(back==NULL){
        cout<<"already empty\n";
    }
    else{
        node *save=back;
        back=(*back).ptr;
        (*save).ptr=NULL;
        free(save);
    }
}
void front(node *&back){
    if(back==NULL){
        cout<<"already empty\n";
    }
    else{
        cout<<(*back).data<<endl;
    }
}
void size(int m,node *&back){
node *travel=back;
while(travel!=NULL){
    travel=(*travel).ptr;
    ++m;
}
cout<<m<<endl;
}
void isempty(node *&back){
  if(back==NULL){
        cout<<"yes";
    }  
    else{
        cout<<"no";
    }
}
};
int main(){
node *a;
node *back;
int data,capacity,operation,m=0,s=0;
cout<<"enter capacity: ";
cin>>capacity;
while(1){
cout<<"enter operation 1-push,2-pop,3-front,4-isempty,5-size,6-exit: ";
cin>>operation;
if(operation==1){
    if(s==capacity){
        cout<<"already full\n";
    }
    else{
        cout<<"enter data: ";
        cin>>data;
       (*a).push(data,a,s,back);
    }
}
else if(operation==2){
    (*a).pop(back);
}
else if(operation==3){
    (*a).front(back);
}
else if(operation==4){
    (*a).isempty(back);
}
else if(operation==5){
    (*a).size(m,back);
}
else if(operation==6){
    break;
}
}
return 0;
}