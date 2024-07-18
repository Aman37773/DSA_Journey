#include<iostream>
#include<iomanip>
#include<unordered_map>
using namespace std;
int main(){
int arr[]={1,2,3,1,2};
int n=5,max,index;
unordered_map<int,int> a;
for(int i=0;i<n;i++){
    ++a[arr[i]];
}
max=a[arr[0]];
index=0;
for(int i=0;i<n;i++){
    if(a[arr[i]]>max){
        max=a[arr[i]];
        index=i;
    }
}
cout<<arr[index];



return 0;
}