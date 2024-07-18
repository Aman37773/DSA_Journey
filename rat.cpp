#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
char value(int arr[100][100],int visited[100][100],string a,int i,int j,int n);
int main(){
int n,i=0,j=0;
string a;
cout<<"enter n: ";
cin>>n;
int arr[100][100],visited[100][100];
cout<<"enter values of matrix: ";
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
    cin>>arr[i][j];
    visited[i][j]=0;
}
}
visited[0][0]=1;
value(arr,visited,a,i,j,n);
return 0;
}
char value(int arr[100][100],int visited[100][100],string a,int i,int j,int n){
string b;
char got;
int m,p;
if(i==n-1&&j==n-1){
cout<<a<<endl;
visited[i][j]=0;
return a.back();
}
if(arr[i+1][j]==1&&visited[i+1][j]==0){
visited[i+1][j]=1;
m=i+1;
p=j;
b="d";
}
else if(arr[i][j+1]==1&&visited[i][j+1]==0){
visited[i][j+1]=1;
m=i;
p=j+1;
b="r";
}
else if(arr[i-1][j]==1&&visited[i-1][j]==0){
visited[i-1][j]=1;
m=i-1;
p=j;
b="u";
}
else if(arr[i][j-1]==1&&visited[i][j-1]==0&&i!=n-1){
visited[i][j-1]=1;
m=i;
p=j-1;
b="l";
}
else{
visited[i][j]=0;
return a.back();
}
got=value(arr,visited,a+b,m,p,n);
if(arr[i-1][j]==1&&visited[i-1][j]==0&&got!='u'){
visited[i-1][j]=1;
value(arr,visited,a+"u",i-1,j,n);
visited[i][j]=0;
return a.back();
}
else if(arr[i][j-1]==1&&visited[i][j-1]==0&&got!='l'&&i!=n-1){
visited[i][j-1]=1;
value(arr,visited,a+"l",i,j-1,n);
visited[i][j]=0;
return a.back();
}
else if(arr[i+1][j]==1&&visited[i+1][j]==0&&got!='d'){
visited[i+1][j]=1;
value(arr,visited,a+"d",i+1,j,n);
visited[i][j]=0;
return a.back();
}
else if(arr[i][j+1]==1&&visited[i][j+1]==0&&got!='r'){
visited[i][j+1]=1;
value(arr,visited,a+"r",i,j+1,n);
visited[i][j]=0;
return a.back();
}
visited[i][j]=0;
return a.back();
}
