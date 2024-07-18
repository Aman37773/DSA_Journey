#include<bits/stdc++.h>
using namespace std;

 int solve(int n,int a[],int target,vector<int> &dp){    /////very simple,just like backtracking but go through all the  responses and finally print

dp[0]=0;
for(int i=1;i<=target;i++){
    int val=INT_MAX;
for(int j=0;j<n;j++){
    if(i-a[j]>=0){

            if(dp[i-a[j]]==INT_MAX){
       val=min(val,dp[i-a[j]]);     //infin+1=-infin so apply conditions
            }
            else{
                val=min(val,dp[i-a[j]]+1);
            }

    }
}
dp[i]=val;
}
return dp[target];
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


vector<int>dp(target+1,INT_MAX);

int get=solve(n,a,target,dp);

if(get==INT_MAX){
cout<<-1;
}
else{
    cout<<get;
}

return 0;
}