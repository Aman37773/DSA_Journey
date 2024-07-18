#include<bits/stdc++.h>
using namespace std;

int solve(int n,int a[],int b[],int i){  //m==1
if(i>=n){
    return 0;
}
int get1=INT_MAX,get2=INT_MAX;
    
        if(a[i]<=a[i-1]||b[i]<=b[i-1]||(a[i]>b[i-1]&&b[i]>a[i-1])){
          swap(a[i],b[i]);
           get1 =  solve(n,a,b,i+1)+1;
           swap(a[i],b[i]);
        }
    if(a[i]>a[i-1]&&b[i]>b[i-1]){
        get2=solve(n,a,b,i+1);
    }   

return min(get1,get2);
}


int main(){
int n,a[100],b[100];
cout<<"enter n: ";
cin>>n;
cout<<"enter values of a: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}
cout<<"enter values of b: ";
for(int i=0;i<n;i++){
    cin>>b[i];
}

cout<<solve(n,a,b,1);


return 0;
}