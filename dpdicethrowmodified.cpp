#include<bits/stdc++.h>
using namespace std;

int solve(int n,int m,int x,int val,int sum ){
if(sum==x&&val==n){
    return 1;
}
if(val==n||sum>x||sum==x&&val!=n){
    return 0;
}
int get=0;
for(int i=1;i<=m;i++){
  get= get+ solve(n,m,x,val+1,sum+i);
}
return get;
}


int main(){
int m,n,x;
cout<<"enter m,n,x: "; //m->faces  n->dice  x->target
cin>>m>>n>>x;
cout<<solve(n,m,x,0,0);

return 0;
}