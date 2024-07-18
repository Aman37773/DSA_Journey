#include<bits/stdc++.h>
using namespace std;

int solve1(int n,int a[]){
    if(n<1){
        return 0;
    }
    if(n==1){
        return a[1];
    }

    int inc=solve1(n-2,a)+a[n];
    int ex=solve1(n-1,a);     ///////////another version of backtracking
    return max(inc,ex);
}

int solve2(int n,int a[]){
    if(n<0){
        return 0;
    }
    if(n==0){
        return a[0];
    }

    int inc=solve2(n-2,a)+a[n];
    int ex=solve2(n-1,a);     ///////////another version of backtracking
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
int get1=solve1(n-1,a);
int get2=solve2(n-2,a);
cout<<max(get1,get2);
return 0;
}