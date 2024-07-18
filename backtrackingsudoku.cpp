#include<bits/stdc++.h>
using namespace std;

void check(int arr[100][100],int n,int p,int q,int count,int &finish){

for(int i=p;i<n;i++){
    for(int j=q;j<n;j++){
    if(arr[i][j]==0){
for(int h=count;h<=n;h++){
    //check row
    int s=0;
    int got=0;
while(s<n){
    if(arr[i][s]==h){
        got=1;
        break;       
    }
    ++s;
}
//check coloumn
s=0;int pot=0;
while(s<n){
    if(arr[s][j]==h){
        pot=1;
        break;
    }
    ++s;
}
//check block
int mot=0;
int val1=i-i%3;int val2=j-j%3;
for(int u=val1;u<val1+3;u++){
    for(int v=val2;v<val2+3;v++){
        if(arr[u][v]==h){
            mot=1;
            break;
        }
    }
}

if(got==0&&pot==0&&mot==0){
    arr[i][j]=h;
    check(arr,n,i,j,1,finish);
    if(finish==1){
        return;
    }
    arr[i][j]=0;
}


}     
return;


        }
    }
    q=0;
}
finish=1;
return;
}

int main(){
int n=9,arr[100][100],count=1,finish=0;
cout<<"enter elements: ";
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
    }
}
check(arr,n,0,0,count,finish);
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}