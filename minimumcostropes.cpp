#include<bits/stdc++.h>
using namespace std;




int main(){
int n,a[100],value1=0,value2=0,value=0;
cout<<"enter n: ";
cin>>n;
cout<<"enter array: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}

priority_queue<int,vector<int>,greater<int>> m;
for(int i=0;i<n;i++){
    m.push(a[i]);
}
//try not to join big sized rope again and again
while(m.size()!=1){
    value1=m.top();
    m.pop();
    value2=m.top();
    m.pop();
    value=value+value1+value2;
    m.push(value1+value2);
}
cout<<value;
return 0;
}