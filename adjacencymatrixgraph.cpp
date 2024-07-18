#include<bits/stdc++.h>
using namespace std;
class graph{
public: 
int arr[100][100];
graph(int n){
for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++){
    arr[i][j]=0;
}
}
}
void creategraph(int u,int v,int direction){
arr[u][v]=1;
if(direction==0){
    arr[v][u]=1;
}
}

void print(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

};

int main(){
int n,m;  //n->nodes,m->edgges     
cout<<"enter no. of nodes and edges: ";
cin>>n>>m;
graph a(n);
for(int i=0;i<m;i++){
    int u,v,direction;
    cout<<"enter nodes: ";
    cin>>u>>v;
    cout<<"enter direction: ";
    cin>>direction;
    a.creategraph(u,v,direction);
}
a.print(n);
return 0;
}