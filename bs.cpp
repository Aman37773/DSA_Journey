#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int value(int *arr,int arsize,int i);
int main(){
int arr[]={1,9,6,0,2};
int arsize=5,i=0;
value(arr,arsize,i);
for(int i=0;i<arsize;i++){
cout<<arr[i]<<endl;
}
return 0;
}
int value(int *arr,int arsize,int i){
if(arsize-1==0){
return 0;
}
if(i==arsize-1){
i=0;
arsize--;
}
if(arr[i]>arr[i+1]){
int c=arr[i];
arr[i]=arr[i+1];
arr[i+1]=c;
}
i++;
value(arr,arsize,i);
return 0;
}
