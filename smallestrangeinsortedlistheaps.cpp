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
int number,d,maxy=0,miny=0;
pair<int,int> ans;
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
m.push(a[i]);
maxy=max(maxy,a[i]->data);
}

ans.first=m.top()->data;
ans.second=maxy;

while(m.size()==number){
   node* on=m.top();
    m.pop();
    if(on->next==NULL){
    break;
    }
    m.push(on->next);
    maxy=max(on->next->data,maxy);
    if(maxy-m.top()->data<ans.second-ans.first){
        ans.first=m.top()->data;
        ans.second=maxy;
    }
}
cout<<ans.first<<" "<<ans.second;

return 0;
}
