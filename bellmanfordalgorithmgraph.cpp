#include<bits/stdc++.h>
using namespace std;
class graph{
    public: 
unordered_map<int,list<pair<int,int>>> adj;


void creategraph(int u,int v,int direction,list<pair<int,int>> &save){  
    pair<int,int> b;
    b.first=v;
    b.second=direction;
    adj[u].push_back(b);
    
    b.first=u;
    b.second=v;
    save.push_back(b);
    
}


void traversal(vector<int> &ans,list<pair<int,int>> save){
  while(save.empty()==0){

    for(auto i:adj[save.front().first]){
        if(i.first==save.front().second){
            if(ans[save.front().first]!=INT_MAX&&ans[save.front().first]+i.second<ans[i.first]){
                ans[i.first]=ans[save.front().first]+i.second;
            }
            
            break;
        }
    }
    save.pop_front();
  }
}




};

int main(){
    graph a;
   
 

int n,m;  //n->nodes,m->edges     
cout<<"enter no. of nodes and edges: ";
cin>>n>>m;

list<pair<int,int>> save;

for(int i=0;i<m;i++){
    int u,v,direction;
    cout<<"enter nodes: ";
    cin>>u>>v;
    cout<<"enter direction: ";
    cin>>direction;
    a.creategraph(u,v,direction,save);
}

int src,dest;
cout<<"enter src,dest: ";
cin>>src>>dest;


vector<int> ans(n+1,numeric_limits<int>::max()); //starting nodes from 1
ans[src]=0;



int c=n-1;
while(c!=0){////////n-1 times because stored edges in random order in save
    a.traversal(ans,save);
    c--;
}

vector<int> bns(ans);
 vector<bool> check(n+1,false);
    a.traversal(bns,save);  ////////nth time

int p=0;
for(int i=1;i<=n;i++){
    if(ans[i]!=bns[i]){
        cout<<"negative loop present";
        p=1;
        break;
    }
}
if(p==0){
    cout<<ans[dest];
}



return 0;
}