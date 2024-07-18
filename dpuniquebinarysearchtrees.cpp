#include<bits/stdc++.h>
using namespace std;

int solve(int n,int i){  //i==n
if(i==0){
return 1;
}
if(i==1||i==2){
    return i;
}
int get=0,ans=0;

for(int i=n;i>=1;i--){
get=solve(i-1,i-1)*solve(n-i,n-i);
ans=ans+get;
}
    
    return ans;
}

int main(){
int n;
cout<<"enter n: ";
cin>>n;

cout<<solve(n,n);

return 0;
}