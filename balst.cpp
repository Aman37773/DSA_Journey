#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
using namespace std;
int main() {
 string a;
 int m=0,n=0;
 cout<<"enter string: ";
 cin>>a;
 stack<char> b;
 for(int i=0;i<a.length();i++){
     if(a[i]=='{'){
       b.push(a[i]);
       ++m;
     }
     else if(a[i]=='}'&&b.empty()==0&&b.top()=='{'){
     b.pop();
     --m;
     }
     else{
         ++n;
      b.push(a[i]);
     }
 }
 if(b.size()%2!=0){
     cout<<"-1 ";
 }
else if(b.empty()==1){
    cout<<0;
}
else if(m==0&&n!=0){
    cout<<n/2;
}
else if(m!=0&&n==0){
    cout<<m/2;
}
else if(m%2==0&&n%2==0){
    if(n>m){
    cout<<n-m+1;
    }
      else  if(m>n){
    cout<<m-n+1;
    }
    else if (m==n){
        cout<<m;
    }
}
else if(m%2!=0&&n%2!=0){
    if(n>m){
    cout<<n;
    }
      else  if(m>n){
    cout<<m;
    }
    else if (m==n){
        cout<<m+1;
    }
}
    return 0;
}