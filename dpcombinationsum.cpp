#include<bits/stdc++.h>
using namespace std;

int solve(int n,int target,int a[],int val){
if(val==target){
return 1;
}
if(val>target){
    return 0;
}
int get=0;
    for(int i=0;i<n;i++){
      get = get + solve(n,target,a,val+a[i]);
    }
    return get;
}


int main(){
int n,a[100],target;
cout<<"enter n: ";
cin>>n;
cout<<"enter values: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}
cout<<"enter target: ";
cin>>target;

cout<<solve(n,target,a,0);

return 0;
}