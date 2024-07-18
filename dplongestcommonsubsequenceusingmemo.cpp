#include<bits/stdc++.h>
using namespace std;

int solve(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
if(i==s1.length()||j==s2.length()){
    return 0;
}
if(dp[i][j]!=-1){
    return dp[i][j];
}
int get=0,get1=0,get2=0;
if(s1[i]==s2[j]){
get=solve(s1,s2,i+1,j+1,dp)+1;
}
else if(s1[i]!=s2[j]){
get1=solve(s1,s2,i,j+1,dp);
get2=solve(s1,s2,i+1,j,dp);
}

return dp[i][j]=max(get,max(get1,get2));
}


int main(){
    string s1,s2;
cout<<"enter string 1: ";
cin>>s1;
cout<<"enter string 2: ";
cin>>s2;

vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
cout<<solve(s1,s2,0,0,dp);
return 0;
}