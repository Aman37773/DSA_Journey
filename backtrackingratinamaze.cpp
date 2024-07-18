#include<bits/stdc++.h>
using namespace std;


void path(int arr[100][100],bool mark[100][100],int m,int i,int j,string &ans,int n){ ///////m==1

    for(int s=m;s<=4;s++){

        if(i==n-1&&j==n-1){
        cout<<ans<<endl;
        ans.pop_back();
    mark[i][j]=false;
    return; 
    }
    
        if(s==1&&i-1>=0&&arr[i-1][j]==1&&mark[i-1][j]==false){
            ans=ans+'U';
            mark[i-1][j]=true;
            path(arr,mark,1,i-1,j,ans,n);
        }
        else if(s==2&&i+1<n&&arr[i+1][j]==1&&mark[i+1][j]==false){
            ans=ans+'D';
            mark[i+1][j]=true;
            path(arr,mark,1,i+1,j,ans,n);
        }
      else  if(s==3&&j+1<n&&arr[i][j+1]==1&&mark[i][j+1]==false){
            ans=ans+'R';
            mark[i][j+1]=true;
            path(arr,mark,1,i,j+1,ans,n);
        }
       else if(s==1&&j-1>=0&&arr[i][j-1]==1&&mark[i][j-1]==false){
            ans=ans+'L';
            mark[i][j-1]=true;
            path(arr,mark,1,i,j-1,ans,n);
        }
    }
    if(i==n-1&&j==n-1){
        cout<<ans<<endl;
    }
    ans.pop_back();
    mark[i][j]=false;
    return; 

}


int main(){
int arr[100][100];
bool mark[100][100];
int n;
cout<<"enter n: ";
cin>>n;
cout<<"enter matrix: ";
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
       mark[i][j]=false;
    }
}
mark[0][0]=true;
string ans;
int m=1,i=0,j=0;
path(arr,mark,1,i,j,ans,n);
return 0;
}