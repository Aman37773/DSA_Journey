#include<bits/stdc++.h>
using namespace std;

int solve(int m,int n,int a[100][100],int p,int q,int &maxy){

if(p==m||q==n){
    return 0;
}

int right=solve(m,n,a,p,q+1,maxy);
int diagonal=solve(m,n,a,p+1,q+1,maxy);
int bottom=solve(m,n,a,p+1,q,maxy);

if(a[p][q]==1){

     int get=min(right,min(bottom,diagonal))+1;
    maxy=max(maxy,get);
    return get;
}
else{
    return 0;
}

}


int main(){
int m,n,a[100][100];
cout<<"enter m,n: ";
cin>>m>>n;
cout<<"enter elements: ";
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>a[i][j];
    }
}
int maxy=0;
solve(m,n,a,0,0,maxy);
cout<<maxy;


return 0;
}