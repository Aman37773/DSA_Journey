#include<bits/stdc++.h>
using namespace std;
int main(){
int n,dp[100];
cout<<"ener n: ";
cin>>n;
int x,y,z;
cout<<"enter x,y,z: ";
cin>>x>>y>>z;

dp[0]=0;


for(int i=1;i<=n;i++){
    int get1=-1,get2=-1,get3=-1;
    if(i-x>=0){
     get1=dp[i-x];
    }
    if(i-y>=0){
    get2=dp[i-y];
    }
    if(i-z>=0){
     get3=dp[i-z];
    }
int val=max(max(get1,get2),get3);
if(val<0){
dp[i]=INT_MIN;
}
else{
    dp[i]=val+1;
}
}

cout<<dp[n];

return 0;
}


/////////solve it