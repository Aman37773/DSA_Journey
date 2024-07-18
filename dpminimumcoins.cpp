#include<bits/stdc++.h>
using namespace std;

void solve(int n,int a[],int target,int ans,int &val){    /////very simple,just like backtracking but go through all the  responses and finally print
if(target==0){
    val=min(ans,val);
    return;
}
for(int i=0;i<n;i++){
    if(target-a[i]>=0){
solve(n,a,target-a[i],ans+1,val);
    }
}
return;
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

int val=numeric_limits<int>::max();
solve(n,a,target,0,val);

if(val==numeric_limits<int>::max()){
cout<<-1;
}
else{
    cout<<val;
}

return 0;
}