#include<bits/stdc++.h>
using namespace std;

int solve(int n,int a[]){
    if(n<0){
        return 0;
    }
    if(n==0){
        return a[0];
    }

    int inc=solve(n-2,a)+a[n];
    int ex=solve(n-1,a);     ///////////another version of backtracking
    return max(inc,ex);
}



int main(){
int n,a[100];
cout<<"enter n: ";
cin>>n;
cout<<"enter elements: ";
for(int i=0;i<n;i++){
    cin>>a[i];
}
cout<<solve(n-1,a);



return 0;
}