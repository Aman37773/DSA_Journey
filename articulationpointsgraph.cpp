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
        
        if(low[neighbour]>=disc[val]&&parent[val]!=-1){  /////this means neighbour least to least connected to val and if val is removed then neighbour will have different component 
            cout<<val<<" is an articulation point"<<endl;   ////root node(parent=-1) can be articulation if it has more than 1 connections but to avoid  complications we have taken it as not an articulation point
        }
        else if(low[neighbour]<=disc[val]){
             low[val]=low[neighbour];
        }
    continue;
    }
    else if(vis[i]==true){

        if(parent[val]==i){
            continue;
        }
        else if(parent[val]!=i){
            //found edge
            low[val]=min(low[val],disc[i]);
            low[parent[val]]=low[val];
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