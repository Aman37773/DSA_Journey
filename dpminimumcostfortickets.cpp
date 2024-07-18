#include<bits/stdc++.h>
using namespace std;

int reach(int iter,int date[],int sum,int n){
    int val=iter;
    while(iter+1<=n&&date[iter+1]<=date[val]+sum-1){
        ++iter;
    }
    ++iter;
    return iter;
}




int solve(int n,int date[],int x,int y,int z,int iter,int cost){
if(iter>n){
    return cost;
}

    int get1=solve(n,date,x,y,z,iter+1,cost+x);
    int mov=reach(iter,date,7,n);
    int get2=solve(n,date,x,y,z,mov,cost+y);
    int pov=reach(iter,date,30,n);
    int get3=solve(n,date,x,y,z,pov,cost+z);
    return min(get1,min(get2,get3));
}


int main(){
int n,date[100],x,y,z;  //x->1 day y->7 days  z->30 days cost
cout<<"enter n: ";
cin>>n;
cout<<"enter dates: ";
for(int i=0;i<n;i++){
    cin>>date[i];
}
cout<<"enter x,y,z: ";
cin>>x>>y>>z;
cout<<solve(n-1,date,x,y,z,0,0);
return 0;
}