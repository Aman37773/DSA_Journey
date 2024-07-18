#include<iostream>
#include<iomanip>
using namespace std;
void sort1(int *arr,int *sorted,int i,int k);
void sort(int *arr,int *sorted,int i,int mid,int k);
int main(){
int arr[]={1,8,4,5,2,3,8,9,0};
int i=0,j=8,sorted[100];
sort1(arr,sorted,i,j);
for(int i=0;i<=j;i++){
cout<<arr[i]<<"\t";
}
return 0;
}
void sort(int *arr,int *sorted,int i,int mid,int k){
    int s=mid+1;
         int count=0;
         int copy=i;
    while(i<=mid&&s<=k){
        if(arr[i]>arr[s]){
            sorted[count]=arr[s];
            s++;
            count++;
        }
        else if(arr[i]<arr[s]){
            sorted[count]=arr[i];
            i++;
            count++;
        }  
        else if(arr[i]==arr[s]){
            sorted[count]=arr[i];
            count++;
            sorted[count]=arr[s];
            count++;
            i++;
            s++;
        }  

        if(i<=mid&&s>k){
            while(i<=mid){
                sorted[count]=arr[i];
                i++;
                count++;
            }
        }   
        else if(i>mid&&s<=k){
            while(s<=k){
                sorted[count]=arr[s];
                s++;
                count++;
            }
        }   
    }
    for(int g=0;g<count;g++){
        arr[copy]=sorted[g];
        copy++;
    }
    return;
}


void sort1(int *arr,int *sorted,int i,int k){
if(i==k){
return;
}
int mid=(i+k)/2;
sort1(arr,sorted,i,mid);
sort1(arr,sorted,mid+1,k);
sort(arr,sorted,i,mid,k);
return;
}
