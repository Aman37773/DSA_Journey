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


void creategraph(int u,int v,int direction,map<int,list<pair<int,int>>> &ordered){
    pair<int,int> a;
    a.first=v;
    a.second=direction;
    adj[u].push_back(a);
    a.first=u;
     adj[v].push_back(a);

    a.first=u;
    a.second=v;
        ordered[direction].push_back(a);

    
}

void check(vector<int> &parent,map<int,list<pair<int,int>>>&ordered,int val,vector<int> &rank,int &total){
    
    for(auto i:ordered[val]){
      int  u=i.first;
      int  v=i.second;
if(ultimateparent(parent,u)!=ultimateparent(parent,v)){
       if(rank[ultimateparent(parent,u)]>=rank[ultimateparent(parent,v)]){
        parent[ultimateparent(parent,v)]=ultimateparent(parent,u);
        ++rank[ultimateparent(parent,u)];
       }
      else if(rank[ultimateparent(parent,u)]<rank[ultimateparent(parent,v)]){
        parent[ultimateparent(parent,u)]=ultimateparent(parent,v);
        ++rank[ultimateparent(parent,v)];
       }
       
       
    total=total+val;
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

int total=0;
map<int,list<pair<int,int>>> ordered;


for(int i=0;i<m;i++){
    int u,v,direction;
    cout<<"enter nodes: ";
    cin>>u>>v;
    cout<<"enter direction: ";
    cin>>direction;
    a.creategraph(u,v,direction,ordered);
}

for(auto i:ordered){
a.check(parent,ordered,i.first,rank,total);
}


cout<<total;






return 0;
}