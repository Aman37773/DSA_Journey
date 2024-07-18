#include<bits/stdc++.h>
using namespace std;
class graph{
    public: 
unordered_map<int,list<int>> adj;

void creategraph(int u,int v,int direction){
    adj[u].push_back(v);
    if(direction==0){
        adj[v].push_back(u);
    }
}

void print(){
for(auto i:adj){
    cout<<i.first<<" ";
    for(auto j:i.second){
cout<<j<<", ";
    }
    cout<<endl;
}
}



};



int main(){
    graph a;
int n,m;  //n->nodes,m->edgges     
cout<<"enter no. of nodes and edges: ";
cin>>n>>m;
for(int i=0;i<m;i++){
    int u,v,direction;
    cout<<"enter nodes: ";
    cin>>u>>v;
    cout<<"enter direction: ";
    cin>>direction;
    a.creategraph(u,v,direction);
}
a.print();
return 0;
}