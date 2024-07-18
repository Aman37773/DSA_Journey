#include<iostream>
#include<iomanip>
using namespace std;
int main(){
int arr[100][100],m,n,prr[100],area=0,areaa=0,nextarea=0;
cout<<"enter m,n: ";
cin>>m>>n;
cout<<"enter elements: ";
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
        prr[j]=0;
    }
}
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(arr[i][j]==0){
            prr[j]=0;
            continue;
        }
        prr[j]=prr[j]+arr[i][j];
    }
for(int p=0;p<n;p++){
    int m=0;
    for(int q=p+1;q<n;q++){
        if(prr[p]<=prr[q]){
            ++m;
        }
        else{
            break;
        }
    }
    for(int r=p;r>=0;r--){
       if(prr[p]<=prr[r]){
            ++m;
        } 
        else{
            break;
        }
    }
area=prr[p]*m;
if(area>areaa){
    areaa=area;
}
}
if(areaa>nextarea){
    nextarea=areaa;
}
}
cout<<nextarea;
return 0;
}