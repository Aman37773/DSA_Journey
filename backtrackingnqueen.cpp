#include<bits/stdc++.h>
using namespace std;
void ways(bool mark[100][100],int p,int q,int n,string &ans){
if(p>=n){
    cout<<ans<<endl;
    ans.pop_back();
ans.pop_back();
    return;
}
for(int t=q;t<n;t++){

if(mark[t][p]==false){
char a=t+'0';
char b=p+'0';
ans=ans+a;
ans=ans+b;
for(int k=p;k<n;k++){
    mark[t][k]=true;
}

int i=t,j=p;
while(i<n&&j<n){
         mark[i][j]=true;
    ++i;++j;
}
i=t,j=p;
while(i>=0&&j<n){
    mark[i][j]=true;
    --i;++j;
}

ways(mark,p+1,0,n,ans);

for(int k=p;k<n;k++){
    mark[t][k]=false;
}

i=t,j=p;
while(i<n&&j<n){
    mark[i][j]=false;
    ++i;++j;
}
i=t,j=p;
while(i>=0&&j<n){
    mark[i][j]=false;
    --i;++j;
}
}

}
ans.pop_back();
ans.pop_back();
return;


}


int main(){
int n;
bool mark[100][100];
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        mark[i][j]=false;
    }
}
cout<<"enter n: ";
cin>>n;
string ans;
ways(mark,0,0,n,ans);
return 0;
}