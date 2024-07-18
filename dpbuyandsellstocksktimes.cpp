#include<bits/stdc++.h>
using namespace std;

int solve(int n,int a[],bool b,int m,int val,int s,int k){
if(m==n||s==k){
    return 0;
}
int profit=0,maxy=0;
for(int i=m;i<n;i++){
    if(b==false){
int get=solve(n,a,true,i+1,a[i],s,k);
maxy=max(maxy,get);
}

else if(b==true){
    if(a[i]>val){
        profit=a[i]-val+solve(n,a,false,i+1,val,s+1,k);
        maxy=max(maxy,profit);
    }
}
}
return maxy;
}


int main(){
int n,a[100],k;
cout<<"enter n: ";
cin>>n;
cout<<"enter values: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}
cout<<"enter k: ";
cin>>k;
cout<<solve(n,a,false,0,0,0,k);

return 0;
}