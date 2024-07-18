#include<bits/stdc++.h>
using namespace std;
class graph{
    public: 
unordered_map<int,list<int>> adj;


void creategraph(int u,int v){   
    adj[u].push_back(v);
     adj[v].push_back(u); 
}

void dfs(vector<int> &disc,vector<int> &parent,vector<int> &low,vector<bool> &vis,int &tim,int val,int neighbour){
disc[val]=tim;
vis[val]=true;
low[val]=tim;
for(auto i:adj[val]){
    if(vis[i]==false){
        parent[i]=val;
        neighbour=i;
        dfs(disc,parent,low,vis,++tim,i,neighbour);
        low[val]=min(low[val],low[neighbour]);
        if(low[neighbour]>disc[val]){
            cout<<"bridge found between "<<val<<" "<<neighbour<<endl;
        }
    }
    else if(vis[i]==true){

        if(parent[val]==i){
            continue;
        }
        else if(parent[val]!=i){
            //found edge
            low[val]=min(low[val],disc[i]);
        }

    }
}
return;
}




};

int main(){
    graph a;
   
 

int n,m;  //n->nodes,m->edges     
cout<<"enter no. of nodes and edges: ";
cin>>n>>m;

vector<int> disc(n,-1);  //vector strts from 0 and starting nodes from 0 
vector<int> parent(n,-1);
vector<int> low(n,-1);
vector<bool> vis(n,false);








for(int i=0;i<m;i++){
    int u,v;
    cout<<"enter nodes: ";
    cin>>u>>v;
    a.creategraph(u,v);
}

int val=0;
int neighbour;
a.dfs(disc,parent,low,vis,val,val,neighbour);





return 0;
}

