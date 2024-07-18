#include<bits/stdc++.h>
using namespace std;

int solve(string s1,string s2,int i,int j){
if(i==s1.length()||j==s2.length()){
    return 0;
}
int get=0,get1=0,get2=0;
if(s1[i]==s2[j]){
get=solve(s1,s2,i+1,j+1)+1;
}
else if(s1[i]!=s2[j]){
get1=solve(s1,s2,i,j+1);
get2=solve(s1,s2,i+1,j);
}

return max(get,max(get1,get2));
}


int main(){
    string s1,s2;
cout<<"enter string 1: ";
cin>>s1;
for(int i=0;i<s1.length();i++){
    s2=s2+s1[i];
}


cout<<solve(s1,s2,0,0);
return 0;
}