#include<bits/stdc++.h>
using namespace std;
int main(){
int n,a[100];
cout<<"enter n: ";
cin>>n;
cout<<"enter values: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}

int profit=0;
int val=a[0];
for(int i=1;i<n;i++){
int diff=a[i]-val;
profit=max(profit,diff);
val=min(val,a[i]);
}
cout<<profit;
return 0;
}