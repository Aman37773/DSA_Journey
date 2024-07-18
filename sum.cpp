#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int value(int *arr,int n,int sum);
int main(){
int arr[]={1,2,5,6,7};
cout<<"sum is:  " <<value(arr,5,0);
return 0;
}
int value(int *arr,int n,int sum){
    if(n==0){
    return sum;
    }
sum=sum+arr[n-1];
n--;
int got=value(arr,n,sum);
return got;
}