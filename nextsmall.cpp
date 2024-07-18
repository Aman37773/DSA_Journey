#include<iostream>
#include<iomanip>
using namespace std;
int main(){
int arr[100],size;
cout<<"enter size: ";
cin>>size;
cout<<"enter elements: ";
for(int i=0;i<size;i++){
    cin>>arr[i];
}
for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
        if(arr[j]<arr[i]){
            cout<<arr[j]<<"\t";
            break;
        }
        if(j==size-1){
            cout<<"-1"<<"\t";
        }
    }
if(i==size-1){
    cout<<"-1"<<"\t";
}
}
return 0;
}