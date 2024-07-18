#include<bits/stdc++.h>
using namespace std;

int solve(int n,int a[],bool b,int m,int val,int fee){
if(m==n){
    return 0;
}
int profit=0,maxy=0;
for(int i=m;i<n;i++){
    if(b==false){
int get=solve(n,a,true,i+1,a[i],fee);
maxy=max(maxy,get);
}

else if(b==true){
    if(a[i]>val){
        profit=a[i]-val-fee+solve(n,a,false,i+1,val,fee);
        maxy=max(maxy,profit);
    }
}
}
return maxy;
}


int main(){
int n,a[100],fee;
cout<<"enter n: ";
cin>>n;
cout<<"enter values: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}
cout<<"enter transaction fee: ";
cin>>fee;
cout<<solve(n,a,false,0,0,fee);

return 0;
}