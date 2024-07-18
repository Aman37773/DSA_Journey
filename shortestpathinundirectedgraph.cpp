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

void bfstraversal(map<int,bool> &check,map<int,int> &loopcheck,int src){
    queue<int> q;
    for(auto i:adj){
        if(i.first==src){
            check[i.first]=true;
            q.push(i.first);
            loopcheck[i.first]=-1;
            cout<<i.first<<" ";
           mainbfstraversal(check,q,q.front(),loopcheck);   
           break;            
    }
        }
        return;
    }
    



void mainbfstraversal(map<int,bool> &check,queue<int> &q,int val,map<int,int> &loopcheck){
if(q.empty()==1){
    return ;
}
if(adj.find(val)!=adj.end()){
for(auto j:adj[val]){
    if(check[j]==false){
    q.push(j);
    check[j]=true;
    cout<<j<<" ";
    loopcheck[j]=val;
    }
}
}
 q.pop();
   
    mainbfstraversal(check,q,q.front(),loopcheck);
    return;
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

int src,dest;
cout<<"enter src and dest: ";
cin>>src>>dest;

a.bfstraversal(check,loopcheck,src);

int arr[100];
arr[0]=dest;
int i=1;
int get=dest;
while(loopcheck[get]!=-1){
get=loopcheck[get];
arr[i]=get;
++i;
}
cout<<endl;
for(int j=i-1;j>=0;j--){
   cout<<arr[j]<<" ";
}


return 0;
}