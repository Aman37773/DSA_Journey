#include<iostream>
#include<iomanip>
using namespace std;
int next(int arr[],int i,int size){
    int m=0;
for(int j=i+1;j<size;j++){
if(arr[i]<=arr[j]){
    ++m;
}
}
return m;
}
int prev(int arr[],int i,int size){
    int m=0;
for(int j=i-1;j>=0;j--){
if(arr[i]<=arr[j]){
    ++m;
}
}
return m;
}
int main(){
int arr[100],size,area=0,areaa=0;
cout<<"enter size: ";
cin>>size;
cout<<"enter elements: ";
for(int i=0;i<size;i++){
    cin>>arr[i];
}
for(int i=0;i<size;i++){
    int nextt=next(arr,i,size);
    int prevv=prev(arr,i,size);
area=arr[i]*(nextt+prevv+1);
if(area>areaa){
    areaa=area;
}
}
cout<<areaa;
return 0;
}