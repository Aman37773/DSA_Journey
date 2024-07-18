#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int value(int *arr);


int main(){
int arr[]={1,2,3};
value(arr);
return 0;
}

int value(int *arr){
cout<<arr[1];
}