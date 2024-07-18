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

void dfstraversal(map<int,bool> &check,stack<int> &topolo){
    queue<int> q;
    for(auto i:adj){
        if(check[i.first]==false){
            q.push(i.first);
            check[i.first]=true;
            cout<<i.first<<" ";
        maindfstraversal(check,q,q.front(),topolo);
        q.pop();
        }
    }
    return;
}


void maindfstraversal(map<int,bool> &check,queue<int> &q,int val,stack<int> &topolo){
if(q.empty()==1){
    return;
}
if(adj.find(val)!=adj.end()){
for(auto j:adj[val]){
    if(check[j.first]==false){
    q.push(j.first);
    check[j.first]=true;
    cout<<j.first<<" ";
    q.pop();
maindfstraversal(check,q,q.front(),topolo);
    }
}
}
topolo.push(val);
return;
}

void allotment(vector<int> &ans,int val){

for(auto i:adj){
    if(i.first==val){
        for(auto j:adj[i.first]){
            if(ans[i.first]+j.second<ans[j.first]){
                ans[j.first]=ans[i.first]+j.second;
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

a.dfstraversal(check,topolo);
cout<<endl;

queue<int> save1;/////////////////
queue<int> save2;///////////  save1===save2

vector<int> ans(n,numeric_limits<int>::max());   //////vector is initiated with 0 so have nodes of graph from 0


while(topolo.empty()==0){
    cout<<topolo.top()<<" ";     
   save1.push(topolo.top());
   topolo.pop();
}

save2=save1;
cout<<endl;
int src;
cout<<"enter src: ";
cin>>src;

        ans[src]=0;
      
while(save2.empty()==0){
if(ans[save2.front()]!=numeric_limits<int>::max()){
a.allotment(ans,save2.front());
}
save2.pop();
}

while(save1.empty()==0){
    if(ans[save1.front()]==numeric_limits<int>::max()){
        cout<<"infi"<<" ";
        save1.pop();
        continue;
    }
    cout<<ans[save1.front()]<<" ";
save1.pop();
}


return 0;
}