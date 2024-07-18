#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,start[100],end[100];
    cout<<"enter n: ";
    cin>>n;
    cout<<"enter start: ";
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    cout<<"enter end: ";
    for(int i=0;i<n;i++){
        cin>>end[i];
    }
vector<pair<int,int>> a;
     pair<int,int> b;
     for(int i=0;i<n;i++){
         b={start[i],end[i]};
         a.push_back(b);
     }
     
     sort(a.begin(),a.end());
     
     int ans=1;
     
     b=a.front();
    int s=1;
     for(auto i:a){
         
         if(s==0){
         if(i.first>b.second){
             ++ans;
              b.first=i.first;
                 b.second=i.second;
         }
         else{
             if(i.second<b.second){
                 b.first=i.first;
                 b.second=i.second;
             }
         }
         }
         s=0;
     }
     
     
     
      cout<<ans;
     
return 0;
}