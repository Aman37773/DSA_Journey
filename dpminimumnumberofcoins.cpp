#include<bits/stdc++.h>
using namespace std;
int s=0;
int back(int target,int a[100],int n,int &val,int &ans){
if(val==target){
    s=1;
    return ans;
}
for(int i=0;i<n;i++){
if(val+a[i]<=target){
    val=val+a[i];
    ++ans;
    back(target,a,n,val,ans);
    if(s==1){
        return ans;
    }
    val=val-a[i];
}
}
return -1;
}



int main(){
int n,a[100],target;
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
cin>>target;
sort(a,a+n);
int val=0,ans=0;
cout<<back(target,a,n,val,ans);
return 0;
}