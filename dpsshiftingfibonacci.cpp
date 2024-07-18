#include<iostream>
#include<iomanip>
using namespace std;
int main(){
int n;
cout<<"enter n: ";
cin>>n;

int prev=0,cur=1;

if(n==0){
    cout<<prev;
    return 0;
}

for(int i=2;i<=n;i++){
    int val=cur;
cur=cur+prev;
prev=val;
}

cout<<cur;



return 0;
}

//time=o(n)
//space=o(1)