#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int value(int *nums,int *arr,int *prr,int i,int n,int arcount,int prcount,int iter);
int main(){
int nums[]={1,2,5,6};
int i=0,n=3,arcount=0,prcount=0,iter=0;
int arr[100],prr[100];
arr[arcount]=nums[i];
arcount++;
i++;
arr[arcount]=100;
for(int k=0;k<=arcount;k++){
prr[k]=arr[k];
}
prcount=arcount;
arcount=0;
value(nums,arr,prr,i,n,arcount,prcount,iter);
int final=pow(2,n+1);
for(int k=0;k<final;k++){
if(prr[k]==100){
cout<<"$$"<<"\n";
continue;
}
cout<<prr[k]<<"\n";
}
return 0;
}
int value(int *nums,int *arr,int *prr,int i,int n,int arcount,int prcount,int iter){
if(arcount>prcount){
prcount=iter-1;
arcount=0;
for(int k=0;k<iter;k++){
prr[k]=arr[k];
}
iter=0;
i++;
}
if(i==n+1){
return 0;
}
if(prr[arcount]==100){
arr[iter]=prr[arcount];
iter++;
arr[iter]=nums[i];
arcount++;
iter++;
}
else{
arr[iter]=prr[arcount];
iter++;
arr[iter]=prr[arcount]*10+nums[i];
iter++;
arcount++;
}
value(nums,arr,prr,i,n,arcount,prcount,iter);
return 0;
}
// , 1       
//2 , ,12,1  
//25,2,5, ,125,12,15,1
//256,25,26,2,56,5,6, ,1256,125,126,12,156,15,16,1