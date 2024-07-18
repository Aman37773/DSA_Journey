#include<bits/stdc++.h>
#include<queue>
using namespace std;
void insert(priority_queue<int,vector<int>> &maxy,priority_queue<int,vector<int>,greater<int>> &miny,int data){
if(maxy.size()>miny.size()){
    if(data<=maxy.top()){
        maxy.push(data);
        miny.push(maxy.top());
        maxy.pop();
    }
    else{
    miny.push(data);
    }
}
else if(maxy.size()==miny.size()){
if(maxy.size()==0||data<=maxy.top()){
    maxy.push(data);
}
else{
    miny.push(data);
    int val=miny.top();
    miny.pop();
    maxy.push(val);
}
}

if(maxy.size()>miny.size()){
    cout<<maxy.top()<<endl;
}
else if(maxy.size()==miny.size()){
    float store=(maxy.top()+miny.top())/2.0;
cout<<store<<endl;
}

return;
}


int main(){
int n,arr[100000];
cout<<"enter n: ";
cin>>n;
priority_queue<int,vector<int>> maxy;   //n sized
priority_queue<int,vector<int>,greater<int>> miny; //n-1 sized
for(int i=0;i<n;i++){
    cout<<"enter "<<i+1<<"th element: ";
    cin>>arr[i];
    insert(maxy,miny,arr[i]);
}
return 0;
}