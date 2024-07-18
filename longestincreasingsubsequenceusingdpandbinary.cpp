#include<bits/stdc++.h>
using namespace std;

int main(){
int n,a[100];
cout<<"enter n: ";
cin>>n;
cout<<"enter elements: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}
vector<int> ans;
ans.push_back(a[0]);

for(int i=1;i<n;i++){
if(a[i]>ans.back()){
    ans.push_back(a[i]);
}
else{
for(int j=ans.size()-1;j>=0;j--){
    if(ans[j]<a[i]){
        ans[j+1]=a[i];
        break;
    }
    if(ans[j]==a[i]){
        ans[j]=a[i];
        break;
    }
    else if(j==0){
        ans[j]=a[i];
        break;
    }
}
}
}
cout<<ans.size();

return 0;
}