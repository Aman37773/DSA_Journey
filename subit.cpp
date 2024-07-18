#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main(){
int arr[]={1,2,5,6};
int n=4,k,i,j;
for(i=0;i<n;i++){
cout<<arr[i]<<endl;
for(int k=i+1;k<n;k++){
cout<<arr[i];
cout<<arr[k]<<endl;
}
k=i+1;
for(int j=k+1;j<n;j++){
cout<<arr[i];
cout<<arr[k];
cout<<arr[j]<<endl;
}
j=k+1;
for(int m=j+1;m<n;m++){
    cout<<arr[i];
cout<<arr[k];
cout<<arr[j];
cout<<arr[m]<<endl;
}
}
    



return 0;
}