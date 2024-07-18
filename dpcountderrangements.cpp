#include<bits/stdc++.h>
using namespace std;

void solve(int n,vector<bool> a,int val,int &ans){
    if(val>n){
        ++ans;
    }
    for(int i=0;i<=n;i++){
        if(val!=i&&a[i]==false){
            a[i]=true;
            solve(n,a,val+1,ans);
            a[i]=false;
        }
    }
return;
}


int main(){
int n;
cout<<"enter n: ";
cin>>n;
vector<bool> a(n,false);
int ans=0;
solve(n-1,a,0,ans);
cout<<ans;
return 0;
}