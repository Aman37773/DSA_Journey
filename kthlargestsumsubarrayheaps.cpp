#include<bits/stdc++.h>
using namespace std;




int main(){
int n,arr[100],value=0,k;
priority_queue<int,vector<int>,greater<int>> a;
cout<<"enter n: ";
cin>>n;
cout<<"enter data: ";
for(int i=0;i<n;i++){
cin>>arr[i];
}
cout<<"enter k: ";
cin>>k;
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
value=value+arr[j];
if(a.size()<k){
a.push(value);
}
else if(a.top()<value){
a.pop();
a.push(value);
}
    }
    value=0;
}

cout<<a.top();


return 0;
}