#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int sort1(int i,int index,int *arr);
int sort2(int index,int j,int *arr,int indexx);
int main(){
int arr[]={2,8,6,4,2,7};
int i=0,j=5,count=0;
int key=arr[0];
for(int i=1;i<=j;i++){
if(key>=arr[i]){
count++;
}
}
int c=arr[count];
arr[count]=key;
arr[0]=c;
while(i!=count&&j!=count){
if(arr[i]>key&&arr[j]>key){
j--;
}
else if(arr[i]>=key&&arr[j]<=key){
c=arr[i];
arr[i]=arr[j];
arr[j]=c;
i++;
j++;
}
else if(arr[i]<key&&arr[j]>key){
i++;
j++;
}
else if(arr[i]<key&&arr[j]<key){
i++;
}
}
i=0;
j=5;
int index=count-1;
sort1(i,index,arr);
index=count+1;
int indexx=index;
sort2(index,j,arr,indexx);
j=5;
for(int i=0;i<=j;i++){
cout<<arr[i]<<endl;
}
return 0;
}
int sort1(int i,int index,int *arr){
if(index<=0){
return 0;
}
if(arr[i]>arr[i+1]){
int c=arr[i];
arr[i]=arr[i+1];
arr[i+1]=c;
}
i++;
if(i==index){
index--;
i=0;
}
sort1(i,index,arr);
return 0;
}
int sort2(int index,int j,int *arr,int indexx){
if(j==index){
return 0;
}
if(arr[index]>arr[index+1]){
int c=arr[index];
arr[index]=arr[index+1];
arr[index+1]=c;
}
index++;
if(index==j){
j--;
index=indexx;
}
sort2(index,j,arr,indexx);
return 0;
}







