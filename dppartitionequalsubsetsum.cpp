#include<bits/stdc++.h>
using namespace std;

bool solve(int n,int a[],int target,int m,int sum){
if(sum==target){
    return true;
}
if(m==n){
    return false;
}

    for(int i=m;i<n;i++){
      bool get =  solve(n,a,target,i+1,sum+a[i]);
      if(get==true){
        return true;
      }
    }
return false;
}

int main(){
int n,a[100],net=0;
cout<<"enter n: ";
cin>>n;
cout<<"enter values: ";
for(int i=0;i<n;i++){
    cin>>a[i];
    net=net+a[i];
}

if(net%2!=0){
    cout<<"no";
}
else{
cout<<solve(n,a,net/2,0,0);
}
return 0;
}