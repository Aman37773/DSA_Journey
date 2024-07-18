#include<bits/stdc++.h>
using namespace std;



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

vector<int> dp(target+1,-1);

dp[0]=1;

for(int i=1;i<=target;i++){
    int get=0;
    for(int j=0;j<n;j++){
        if(i-a[j]>=0){
            get=get+dp[i-a[j]];
        }        
    }
    dp[i]=get;
}

cout<<dp[target];
return 0;
}