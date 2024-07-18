#include<bits/stdc++.h>
using namespace std;
void sort(int *b,int data,int i){
   for(int j=i-1;j>=0;j--){
    if(data>b[j]){
        break;
    }
    else if(data<b[j]){
        int val=b[j];
        b[j]=data;
        b[j+1]=val;
    }
   }
   return;
}


int main(){
int n,arr[100000],b[100000];
cout<<"enter n: ";
cin>>n;
for(int i=0;i<n;i++){
    cout<<"enter "<<i+1<<"th element: ";
    cin>>arr[i];
    b[i]=arr[i];
    sort(b,arr[i],i);
    if((i+1)%2==0){
        cout<<(b[(i+1)/2-1]+b[(i+1)/2])/2.0<<endl;
    }
    else{
        cout<<b[(i+1)/2]<<endl;
    }
}
return 0;
}