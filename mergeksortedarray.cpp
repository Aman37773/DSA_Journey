#include<bits/stdc++.h>
#include<queue>
using namespace std;
class  node{
public: 
int data;
int i;
int j;
};

class compare{
public:
bool operator()(node a,node b){
    return a.data>b.data;
}
};


int main(){
 node  a[100][100];  // node *ptr is used to dynamically create classes
int n,k[100],number,i=0,j=0;
list<int> ans;
priority_queue<node,vector<node>, compare> m; //on basis of compare it will form min heap
cout<<"enter number: ";
cin>>number;
for(int i=0;i<number;i++){
cout<<"enter k["<<i<<"]: ";
cin>>k[i];
cout<<"enter elements: ";
    for(int j=0;j<k[i];j++){
cin>>a[i][j].data;
a[i][j].i=i;
a[i][j].j=j;
    }
}

for(int i=0;i<number;i++){
    m.push(a[i][0]);
}

while(m.size()!=0){
 ans.push_back(m.top().data);
 i=  m.top().i;
 j=m.top().j; 
 if(j+1<k[i]){
    m.pop();
    j=j+1;
    m.push(a[i][j]);
 }
 else{
    m.pop();
 }
}


while(ans.empty()==0){
    cout<<ans.front()<<" "; //we would have directly printed m.top().data without creating ans list but to make easy understanding we did this
    ans.pop_front();
}


return 0;
}