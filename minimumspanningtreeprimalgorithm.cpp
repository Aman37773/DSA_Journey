#include<bits/stdc++.h>
using namespace std;
class graph{
    public: 
unordered_map<int,list<pair<int,int>>> adj;

void creategraph(int u,int v,int direction){
    pair<int,int> a;
    a.first=v;
    a.second=direction;
    adj[u].push_back(a);
}

void initialize(map<int,bool> &check,int u,int v){
check[u]=false;
check[v]=false;
}



void allotment(vector<int> &ans,int node,vector<int> &got){

for(auto i:adj){
    if(i.first==node){
        for(auto j:adj[i.first]){
            if(j.second<ans[j.first]){
                ans[j.first]=j.second;
                got[j.first]=i.first;
            }
        }
        break;
    }
}



}


};

int main(){
    graph a;
    map<int,bool> check;
    stack<int> topolo;
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





vector<int> ans(n,numeric_limits<int>::max());   //////vector is initiated with 0 so have nodes of graph from 0
vector<bool> mark(n,false);
vector<int> got(n,-1);  //dist,node
got[0]=-1;





        ans[0]=0;
      
while(1){
    int s=0;
    int node;
for(int i=0;i<n;i++){

if(mark[i]==false){
    s=1;
    mark[i]=true;
    node=i;
    break;
}
}
if(s==1){
a.allotment(ans,node,got);
}
else{
    break;
}
}

for(int i:got){
    cout<<i<<" ";
}


return 0;
}