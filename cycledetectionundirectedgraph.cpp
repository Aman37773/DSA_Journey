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

void initialize(map<int,bool> &check,int u){
check[u]=false;
}

void bfstraversal(map<int,bool> &check,map<int,int> &loopcheck){
    queue<int> q;
    for(auto i:adj){
    int val1=i.first;
    loopcheck[val1]=-1;
    if(check[val1]==false){
        q.push(val1);
        check[val1]=true;
        while(q.empty()==0){
            cout<<q.front()<<" ";
        for(auto j:adj[q.front()]){
            if(check[j]==false){
            check[j]=true;
            q.push(j);
            loopcheck[j]=q.front();
        }
        else if(check[j]==true&&loopcheck[q.front()]!=j){
          cout<<"\nloop is present between: "<<j<<" "<<q.front();  
          return;
        }
        }
        q.pop();       
        }       
}
    }
cout<<"loop is not present";
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
    a.initialize(check,u);
}


a.bfstraversal(check,loopcheck);







return 0;
}