#include<bits/stdc++.h>
using namespace std;

int solve(int n,int iter){
if(n==0){
    return 0;
}
if(n<0){
    return INT_MAX-1;
}
int val=0,get=0,mini=INT_MAX;
    for(int i=1;i<=iter;i++){

        get= solve(n-i*i,iter)+1;

        mini=min(mini,get);
    }
    
    return mini;
}

int main(){
int n;
cout<<"enter n: ";
cin>>n;

int iter=pow(n,0.5);

cout<<solve(n,iter);

return 0;
}