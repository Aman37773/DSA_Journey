#include<bits/stdc++.h>
using namespace std;

int solve(string &a,string &b,int i,int j,vector<vector<int>> &dp){
if(j==b.length()){
    return a.length()-i;
}
if(i==a.length()){
    return b.length()-j;
}
if(dp[i][j]!=-1){
    return dp[i][j];
}
int get=0,get1=0,get2=0,get3=0;
    if(a[i]==b[j]){
       get= solve(a,b,i+1,j+1,dp);
    }
    else if(a[i]!=b[j]){
        //condition 1: remove
        
        get1=solve(a,b,i+1,j,dp)+1;
       

    //condition 2: replace
    
    get2=solve(a,b,i+1,j+1,dp)+1;
    

    //condition 3:insert
    
    get3=solve(a,b,i,j+1,dp)+1;
    
    }
return dp[i][j]=max(get,min(get1,min(get2,get3)));
}


int main(){
string a,b;
cout<<"enter string a: ";
cin>>a;
cout<<"enter string b: ";
cin>>b;
vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,-1));
cout<<solve(a,b,0,0,dp);
return 0;
}