#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<vector<int>> &a,int iter,vector<vector<int>> &ans){
if(iter==n){
    return 0;
}
int get=0,maxy=0;
    for(int i=iter;i<n;i++){
        if(a[i].front()>ans.back().front()&&a[i].back()>ans.back().back()){
            ans.push_back(a[i]);
           int get= solve(n,a,i+1,ans)+1;
           maxy=max(maxy,get);
            ans.pop_back();
        }
    }
    return maxy;
}



int main(){
int n;
cout<<"enter n: ";
cin>>n;
vector<vector<int>> a(n);
cout<<"enter values: ";
for(int i=0;i<n;i++){
int p,q;
cin>>p>>q;
a[i].push_back(p);
a[i].push_back(q);
}
vector<vector<int>> ans(0);
sort(a.begin(),a.end());

 int maxy=0;

for(int i=0;i<n;i++){  
    ans.push_back(a[i]);
    int get=solve(n,a,i+1,ans)+1;
    ans.pop_back();
    maxy=max(maxy,get);
}
cout<<maxy;
return 0;
}