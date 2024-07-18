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



void allotment(vector<int> &ans,queue<pair<int,int>> &rec ,int val){

for(auto i:adj){
    if(i.first==val){
        for(auto j:adj[i.first]){
            if(ans[i.first]+j.second<ans[j.first]){
                ans[j.first]=ans[i.first]+j.second;
                pair<int,int> get;
                get.first=ans[j.first];
                get.second=j.first;
                rec.push(get);
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
queue<pair<int,int>> rec;  //dist,node




int src;
cout<<"enter src: ";
cin>>src;
pair<int,int> get;
get.first=0;
get.second=src;
rec.push(get);
        ans[src]=0;
      
while(rec.empty()==0){

a.allotment(ans,rec,(rec.front()).second);

rec.pop();
}

for(int i:ans){
    if(i==numeric_limits<int>::max()){
        cout<<"infi"<<" ";
        continue;
    }
    cout<<i<<" ";
}


return 0;
}