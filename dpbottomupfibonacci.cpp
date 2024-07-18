#include<iostream>
#include<iomanip>
using namespace std;
int fib(int n,int dp[]){
    dp[0]=0;
    dp[1]=1;

for(int i=2;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
}
return dp[n];
}



int main(){
int n,dp[100];
cout<<"enter n: ";
cin>>n;
cout<<fib(n,dp);
return 0;
}

//time=o(n)
//space=o(n)