#include<bits/stdc++.h>
using namespace std;

void solve(int n,int arr[100][100],bool mark[100][100],int ans,int i,int j,int &val){  //i=2,j=0


if(j==n-1){
    val=min(val,ans);
    return;
}

//right
if(mark[i][j+1]==false&&arr[i][j+1]==1){
    mark[i][j+1]=true;
    solve(n,arr,mark,ans,i,j+1,val);
    mark[i][j+1]=false;
}

//up
if(i-1>=1&&mark[i-1][j]==false&&arr[i-1][j]==1){
    mark[i-1][j]=true;
    solve(n,arr,mark,ans+1,i-1,j,val);
    mark[i-1][j]=false;
}

//up+up
if(i-2>=1&&mark[i-2][j]==false&&arr[i-2][j]==1){
    mark[i-2][j]=true;
    solve(n,arr,mark,ans+1,i-2,j,val);
    mark[i-2][j]=false;
}

//down
if(i+1<=3&&mark[i+1][j]==false&&arr[i+1][j]==1){
  mark[i+1][j]=true;
    solve(n,arr,mark,ans+1,i+1,j,val);
    mark[i+1][j]=false;
}

//down+down
if(i+2<=3&&mark[i+2][j]==false&&arr[i+2][j]==1){
   mark[i+2][j]=true;
    solve(n,arr,mark,ans+1,i+2,j,val);
    mark[i+2][j]=false;
}

return ;
}

int main(){
int n,obst[100],arr[100][100];
bool mark[100][100];
cout<<"enter n: ";
cin>>n;
cout<<"enter obstacles: ";
for(int i=0;i<n;i++){
cin>>obst[i];
}

for(int i=1;i<=3;i++){
    for(int j=0;j<n;j++){
        arr[i][j]=1;
        mark[i][j]=false;
    }
}

mark[2][0]=true;

for(int i=1;i<n-1;i++){
    arr[obst[i]][i]=0;
}

int ans=0,val=INT_MAX;

solve(n,arr,mark,ans,2,0,val);

cout<<val;

return 0;
}