#include<bits/stdc++.h>
using namespace std;

int solve(string &a,string &b,int i,int j,vector<vector<int>> &dp){
if(i==a.length()&&j==b.length()){
    return true;
}
if((i!=a.length()&&j==b.length())||(i==a.length()&&j!=b.length())&&b[j]!='*'){
    return false;
}
if(i>a.length()){
    return false;
}

if(a[i]!=b[j]&&b[j]!='?'&&b[j]!='*'){
    return false;
}

if(dp[i][j]!=-1){
    return dp[i][j];
}

bool get1=false,get2=false,get3=false,get4=false;

if(b[j]=='*'){
    
       get2= solve(a,b,i+1,j,dp);
       get4=solve(a,b,i+1,j+1,dp);
    
        get3=solve(a,b,i,j+1,dp);
    }
   else  if(a[i]==b[j]||b[j]=='?'){
      get1=  solve(a,b,i+1,j+1,dp);
    }
    
   bool val1=get2||get3;
   bool val2=get1||get4;
    return dp[i][j]=val1||val2;
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