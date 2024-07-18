#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int m){
     int maxy=0;
for(int i=0;i<m;i++){
    int val=arr[i];
    int get=1; 
    for(int j=i+1;j<m;j++){
        if(arr[j]>=val){
++get;
        }
        else{
            break;
        }
    }
    for(int j=i-1;j>=0;j--){
        if(arr[j]>=val){
++get;
        }
        else{
            break;
        }
    }
maxy=max(maxy,val*get);
}
return maxy;
}


int main(){
int n,m,a[100][100];
cout<<"enter n,m: ";
cin>>n>>m;
cout<<"enter values: ";
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>a[i][j];
    }
}
int arr[100];
int maxy=0;
for(int i=0;i<m;i++){
    arr[i]=0;
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
if(a[i][j]==0){
    arr[j]=0;
}
else{
    ++arr[j];
}
    }
maxy=max(maxy,solve(arr,m));
}

cout<<maxy;


return 0;
}