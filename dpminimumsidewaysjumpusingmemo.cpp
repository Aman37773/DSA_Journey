#include<bits/stdc++.h>
using namespace std;

int solve(int n,int arr[100][100],bool mark[100][100],int i,int j,vector<vector<int>> &dp){  //i=2,j=0


if(j==n-1){
    return 0;
}

if(dp[i][j]!=INT_MAX){
    return  dp[i][j];
}

int get1=INT_MAX,get2=INT_MAX,get3=INT_MAX,get4=INT_MAX,get5=INT_MAX;

//right
if(mark[i][j+1]==false&&arr[i][j+1]==1){
    mark[i][j+1]=true;
   get1 = solve(n,arr,mark,i,j+1,dp);
    mark[i][j+1]=false;
}

//up
if(i-1>=1&&mark[i-1][j]==false&&arr[i-1][j]==1){
    mark[i-1][j]=true;
    get2 = solve(n,arr,mark,i-1,j,dp);
    if(get2!=INT_MAX){
        ++get2;
    }
    mark[i-1][j]=false;
}

//up+up
if(i-2>=1&&mark[i-2][j]==false&&arr[i-2][j]==1){
    mark[i-2][j]=true;
    get3 = solve(n,arr,mark,i-2,j,dp);
     if(get3!=INT_MAX){
        ++get3;
    }
    mark[i-2][j]=false;
}

//down
if(i+1<=3&&mark[i+1][j]==false&&arr[i+1][j]==1){
  mark[i+1][j]=true;
  get4 =  solve(n,arr,mark,i+1,j,dp);
   if(get4!=INT_MAX){
        ++get4;
    }
    mark[i+1][j]=false;
}

//down+down
if(i+2<=3&&mark[i+2][j]==false&&arr[i+2][j]==1){
   mark[i+2][j]=true;
   get5 = solve(n,arr,mark,i+2,j,dp);
    if(get5!=INT_MAX){
        ++get5;
    }
    mark[i+2][j]=false;
}

dp[i][j]=min(get1,min(get2,min(get3,min(get4,get5))));
return dp[i][j];
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

vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));

cout<<solve(n,arr,mark,2,0,dp);

return 0;
}