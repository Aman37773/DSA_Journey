#include<iostream>
#include<iomanip>
using namespace std;
int main(){
int arr[100],size,area=0,areaa=0;
cout<<"enter size: ";
cin>>size;
cout<<"enter elements: ";
for(int i=0;i<size;i++){
    cin>>arr[i];
}
for(int i=0;i<size;i++){
int m=0;
    for(int j=i+1;j<size;j++){
if(arr[i]<=arr[j]){
    ++m;
}
    }
    for(int j=i;j>=0;j--){
        if(arr[i]<=arr[j]){
            ++m;
        }
    }
area=arr[i]*m;
if(area>areaa){
    areaa=area;
}
}
cout<<areaa;
return 0;
}