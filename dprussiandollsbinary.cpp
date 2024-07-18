#include<bits/stdc++.h>
using namespace std;

bool comparator(vector<int> &p,vector<int> &q){
    if(p.front()!=q.front()){
return p.front()<q.front();
    }
    else{
        return p.back()>q.back();
    }
}

int main(){
int n;
cout<<"enter n: ";
cin>>n;
vector<vector<int>> a(n);
cout<<"enter values: ";
for(int i=0;i<n;i++){
int p,q;
cin>>p>>q;
a[i].push_back(p);
a[i].push_back(q);
}

sort(a.begin(),a.end(),comparator);




vector<vector<int>> ans(0);
ans.push_back(a[0]);
for(int i=1;i<n;i++){
    if(a[i].back()>ans.back().back()&&a[i].front()==ans.back().front()){
        ans.pop_back();
        ans.push_back(a[i]);
    }
    else if(a[i].back()>ans.back().back()&&a[i].front()!=ans.back().front()){
        ans.push_back(a[i]);
    }
    else{
          
        for(int j=ans.size()-1;j>=0;j--){
           
                if(a[i].back()>ans[j].back()){
                    ans[j+1]=a[i];
                    break;
                }
                if(a[i].back()==ans[j].back()){
                        
                        break;
                }
                if(j==0){
                    ans[j]=a[i];
                }
        }
    }
   
}

cout<<ans.size();
return 0;
}