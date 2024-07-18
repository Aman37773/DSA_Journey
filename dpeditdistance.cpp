#include<bits/stdc++.h>
using namespace std;

int solve(string &a,string &b,int i,int j){
if(j==b.length()){
    return a.length()-i;
}
if(i==a.length()){
    return b.length()-j;
}
int get=0,get1=0,get2=0,get3=0;
    if(a[i]==b[j]){
       get= solve(a,b,i+1,j+1);
    }
    else if(a[i]!=b[j]){
        //condition 1: remove
        
        get1=solve(a,b,i+1,j)+1;
       

    //condition 2: replace
    
    get2=solve(a,b,i+1,j+1)+1;
    

    //condition 3:insert
    
    get3=solve(a,b,i,j+1)+1;
    
    }
return max(get,min(get1,min(get2,get3)));
}


int main(){
string a,b;
cout<<"enter string a: ";
cin>>a;
cout<<"enter string b: ";
cin>>b;
cout<<solve(a,b,0,0);
return 0;
}