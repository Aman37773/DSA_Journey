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

bool bfstraversal(map<int,bool> &check,map<int,int> &loopcheck){
    queue<int> q;
    for(auto i:adj){
        if(check[i.first]==false){
            q.push(i.first);
            check[i.first]=true;
            cout<<i.first<<" ";
            if(mainbfstraversal(check,q,q.front(),loopcheck)){
                return true;
            }
       
        }
    }
    return false;
}


bool mainbfstraversal(map<int,bool> &check,queue<int> &q,int val,map<int,int> &loopcheck){
if(q.empty()==1){
    return false;
}
if(adj.find(val)!=adj.end()){
for(auto j:adj[val]){
    if(check[j]==false){
    q.push(j);
    check[j]=true;
    cout<<j<<" ";
    loopcheck[j]=val;
    }
    else if(check[j]==true&&loopcheck[val]!=j){
        cout<<"loop is present between "<<j<<" "<<val;
        return true;
    }
}
}
 q.pop();
   return mainbfstraversal(check,q,q.front(),loopcheck);
}
};

int main(){
    graph a;
    map<int,bool> check;
    map<int,int> loopcheck;
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

if(a.bfstraversal(check,loopcheck)==false){
cout<<"loop is not present";
}

return 0;
}