#include<bits/stdc++.h>
using namespace std;
class graph{
    public: 
unordered_map<int,list<pair<int,int>>> adj;


int ultimateparent(vector<int> &parent,int val){
    if(parent[val]==val){
        return val;
    }
   return ultimateparent(parent,parent[val]);
}


void creategraph(int u,int v,int direction,vector<int> &parent,vector<int> &rank){
    pair<int,int> a;
    a.first=v;
    a.second=direction;
    adj[u].push_back(a);
    a.first=u;
     adj[v].push_back(a);
    if(ultimateparent(parent,u)!=ultimateparent(parent,v)){
       if(rank[ultimateparent(parent,u)]>=rank[ultimateparent(parent,v)]){
        parent[ultimateparent(parent,v)]=ultimateparent(parent,u);
        ++rank[ultimateparent(parent,u)];
       }
      else if(rank[ultimateparent(parent,u)]<rank[ultimateparent(parent,v)]){
        parent[ultimateparent(parent,u)]=ultimateparent(parent,v);
        ++rank[ultimateparent(parent,v)];
       }
       
    }
}







};

int main(){
    graph a;
   
 

int n,m;  //n->nodes,m->edges     
cout<<"enter no. of nodes and edges: ";
cin>>n>>m;

vector<int> rank(n+1,0);  //vector strts from 0 but starting nodes from 1 so n+1
vector<int> parent(n+1);
for(int i=1;i<=n;i++){    /////////starting nondes from 1
parent[i]=i;
}


for(int i=0;i<m;i++){
    int u,v,direction;
    cout<<"enter nodes: ";
    cin>>u>>v;
    cout<<"enter direction: ";
    cin>>direction;
    a.creategraph(u,v,direction,parent,rank);
}

int p,q;
cout<<"enter values to check for disjoint: ";
cin>>p>>q;
if(parent[p]==parent[q]){
    cout<<"belongs to same graph";
}
else{
    cout<<"belongs to different graph";
}




return 0;
}