#include<bits/stdc++.h>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node *next;

node(int d){
this->data=d;
this->next=NULL;
}

node* insert(node *a,int d){
    cout<<"enter data: ";
    cin>>d;
    if(d==-1){
        return NULL;
    }
    a=new node(d);
    a->next=insert(a,d);
    return a;
}



};

class compare{
    public:
    bool operator()(node *a,node *b){
        return a->data>b->data;
    }
};

int main(){
node *a[100],*prev;
int number,d;
cout<<"enter number: ";
cin>>number;
for(int i=0;i<number;i++){
    cout<<"enter data for "<<i<<" th list: \n";
        cout<<"enter data: ";
        cin>>d;
       a[i]=new node(d);
       a[i]->next=a[i]->insert(a[i],d);
}

priority_queue<node*,vector<node*> ,compare> m;

for(int i=0;i<number;i++){
while(a[i]!=NULL){
m.push(a[i]);
a[i]=a[i]->next;
}
}

node *save=m.top();
while(m.size()!=1){
   node* on=m.top();
    m.pop();
    on->next=m.top();
}
m.top()->next=  NULL;
while(save!=NULL){
    cout<<save->data<<" ";
    save=save->next;
}

return 0;
}
