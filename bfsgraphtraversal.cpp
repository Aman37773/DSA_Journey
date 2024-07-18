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

void initialize(map<int,bool> &check,int u,int v){
check[u]=false;
check[v]=false;
}

void bfstraversal(map<int,bool> &check){
    queue<int> q;
    for(auto i:adj){
        if(check[i.first]==false){
            q.push(i.first);
            check[i.first]=true;
            cout<<i.first<<" ";
        mainbfstraversal(check,q,q.front());
        }
    }
    

}


void mainbfstraversal(map<int,bool> &check,queue<int> &q,int val){
if(q.empty()==1){
    return;
}
if(adj.find(val)!=adj.end()){
for(auto j:adj[val]){
    if(check[j]==false){
    q.push(j);
    check[j]=true;
    cout<<j<<" ";
    }
}
}
 q.pop();
    mainbfstraversal(check,q,q.front());
}
};

int main(){
    graph a;
    map<int,bool> check;
int n,m;  //n->nodes,m->edges     
cout<<"enter no. of nodes and edges: ";
cin>>n>>m;
for(int i=0;i<m;i++){
    int u,v,direction;
    cout<<"enter nodes: ";
    cin>>u>>v;
    cout<<"enter direction: ";
    cin>>direction;
    a.creategraph(u,v,direction);
    a.initialize(check,u,v);
}


a.bfstraversal(check);







return 0;
}