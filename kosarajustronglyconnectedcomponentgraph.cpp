#include<bits/stdc++.h>
using namespace std;
int total=0;
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

void dfstraversal(map<int,bool> &check,stack<int> &ans){
    queue<int> q;
    for(auto i:adj){
        if(check[i.first]==false){
            q.push(i.first);
            check[i.first]=true;
        maindfstraversal(check,q,q.front(),ans);
        q.pop();
        }
    }
    return;
}


void maindfstraversal(map<int,bool> &check,queue<int> &q,int val,stack<int> &ans){
if(q.empty()==1){
    return;
}
if(adj.find(val)!=adj.end()){
for(auto j:adj[val]){
    if(check[j]==false){
    q.push(j);
    check[j]=true;
    q.pop();
maindfstraversal(check,q,q.front(),ans);
    }
}
}
ans.push(val);
return;
}

//////now dfs traversal with respect to ans on transpose

void dfstraversal2(map<int,bool> &check,stack<int> &ans,map<int,list<int>> &transpose){
    queue<int> q;
    while(ans.empty()==0){
        if(check[ans.top()]==false){
            q.push(ans.top());
            check[ans.top()]=true;
        maindfstraversal2(check,q,q.front(),transpose);
        q.pop();
        ++total;
        }
        ans.pop();
    }
    return;
}


void maindfstraversal2(map<int,bool> &check,queue<int> &q,int val,map<int,list<int>> &transpose){
if(q.empty()==1){
    return;
}
if(transpose.find(val)!=transpose.end()){
for(auto j:transpose[val]){
    if(check[j]==false){
    q.push(j);
    check[j]=true;
    q.pop();
maindfstraversal2(check,q,q.front(),transpose);
    }
}
}
return;
}




void dotranspose(map<int,list<int>> &transpose,map<int,bool> &check ){

    for(auto i:adj){
        check[i.first]=false;
        for(auto j:adj[i.first]){
            transpose[j].push_back(i.first);
            check[j]=false;
       }
    }
}






};

int main(){
    graph a;
    map<int,bool> check;
    stack<int> ans;
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

a.dfstraversal(check,ans);

map<int,list<int>> transpose;
a.dotranspose(transpose,check);

a.dfstraversal2(check,ans,transpose);


cout<<total;




return 0;
}