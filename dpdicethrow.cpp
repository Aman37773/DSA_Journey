#include<bits/stdc++.h>
using namespace std;

void solve(int n,int m,int x,int val,int sum,int &ans){
if(sum==x&&val==n){
    ++ans;
}
if(val==n||sum>x||sum==x&&val!=n){
    return ;
}

for(int i=1;i<=m;i++){
    solve(n,m,x,val+1,sum+i,ans);
}
return ;
}


int main(){
int m,n,x;
cout<<"enter m,n,x: "; //m->faces  n->dice  x->target
cin>>m>>n>>x;
int ans=0;
solve(n,m,x,0,0,ans);
cout<<ans;
return 0;
}