#include<bits/stdc++.h>
using namespace std;
class graph{
    public: 
unordered_map<int,list<int>> adj;

void creategraph(int u,int v,int direction,map<int,int> &indegree){
    adj[u].push_back(v);
    ++indegree[v];
    if(direction==0){
        adj[v].push_back(u);
    }
}



void bfstraversal(map<int,int> &indegree,queue<int> &ans){
    queue<int> q;
    for(auto i:adj){
        if(indegree[i.first]==0){
            q.push(i.first);
        }
    }
    mainbfstraversal(indegree,q,q.front(),ans);
}


void mainbfstraversal(map<int,int> &indegree,queue<int> &q,int val,queue<int> &ans){
if(q.empty()==1){
    return;
}
if(adj.find(val)!=adj.end()){
for(auto j:adj[val]){
   
    --indegree[j];    
    if(indegree[j]==0){
        q.push(j);
    }
    
}
}
ans.push(q.front());
 q.pop();
    mainbfstraversal(indegree,q,q.front(),ans);
    return;
}
};

int main(){
    graph a;
   
    map<int,int> indegree;
    queue<int> ans;
int n,m;  //n->nodes,m->edges     
cout<<"enter no. of nodes and edges: ";
cin>>n>>m;
for(int i=0;i<m;i++){
    int u,v,direction;
    cout<<"enter nodes: ";
    cin>>u>>v;
    cout<<"enter direction: ";
    cin>>direction;
    a.creategraph(u,v,direction,indegree);
   
}


a.bfstraversal(indegree,ans);
cout<<endl;
while(ans.empty()==0){
    cout<<ans.front()<<" ";
    ans.pop();
}





return 0;
}