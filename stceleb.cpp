#include<iostream>
#include<iomanip>
using namespace std;
int main(){
int arr[100][100],size;
cout<<"entr size: ";
cin>>size;
cout<<"enter elements: ";
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        cin>>arr[i][j];
    }
}
int s;
for(int i=0;i<size;i++){
    s=0; 
    for(int j=0;j<size;j++){
        if(i!=j){
        if(arr[i][j]==1||arr[j][i]!=1){
          s=1;
          if(i==size-1){
        cout<<-1;
    }
          break;  
        } 
   }
   
    }
    if(s==1){
        continue;
    }
    else{
        cout<<i<<"  th person is celebrity\n";
        break;
    }
}
return 0;
}