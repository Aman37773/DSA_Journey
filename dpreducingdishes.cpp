#include<bits/stdc++.h>
using namespace std;
int solve(int n,int a[],int iter,int p){  //iter=0,p=1
if(iter==n){
    return 0;
}
int inc=a[iter]*p + solve(n,a,iter+1,p+1);
int ex=solve(n,a,iter+1,p);

return max(inc,ex);

}

int main(){
int n,a[100];
cout<<"enter n: ";
cin>>n;
cout<<"enter satisfaction numbers: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a,a+n);

cout<<solve(n,a,0,1);
return 0;
}