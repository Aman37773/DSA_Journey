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

bool dfstraversal(map<int,bool> &check,map<int,int> &loopcheck,map<int,bool> &dfsvisited){
    queue<int> q;
    for(auto i:adj){
        if(check[i.first]==false){
            q.push(i.first);
            check[i.first]=true;
            dfsvisited[i.first]=true;
            cout<<i.first<<" ";
       if(maindfstraversal(check,q,q.front(),loopcheck,dfsvisited)){
        return true;
       }
       q.pop();
        }
    }
    return false;
}


bool maindfstraversal(map<int,bool> &check,queue<int> &q,int val,map<int,int> loopcheck,map<int,bool> &dfsvisited){

if(adj.find(val)!=adj.end()){
for(auto j:adj[val]){
    if(check[j]==true&&loopcheck[j]!=val&&dfsvisited[j]==true){
        cout<<"loop is present between "<<j<<" "<<val;
        return true;
    }
   else if(check[j]==false){
    q.push(j);
    check[j]=true;
    dfsvisited[j]=true;
    cout<<j<<" ";
    loopcheck[val]=j;
    q.pop();
if(maindfstraversal(check,q,q.front(),loopcheck,dfsvisited)){
    return true;
}
    }
}
}
dfsvisited[val]=false;   //////if function call breaking  at node then loop cannot be formed at that node so thats why marking false 
return false;
}



};

int main(){
    graph a;
    map<int,bool> check;
    map<int,int> loopcheck;
     map<int,bool> dfsvisited;
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

if(!a.dfstraversal(check,loopcheck,dfsvisited)){
cout<<"loop is not present";
}

return 0;
}