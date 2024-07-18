#include<iostream>
#include<iomanip>
#include<stack>
#include<string>
using namespace std;

int main(){
    string a;
    cout<<"enter string: ";
    cin>>a;
stack<char> b;
for(int i=0;i<a.length();i++){
 if(a[i]=='('||a[i]=='{'||a[i]=='['){
    b.push(a[i]);
 }   
 else if(a[i]==')'&&b.top()=='('){
    b.pop();
 }
 else if(a[i]=='}'&&b.top()=='{'){
    b.pop();
 }
 else if(a[i]==']'&&b.top()=='['){
    b.pop();
 }
}
if(b.empty()==1){
    cout<<"balanced";
}
else{
    cout<<"not balanced";
}
return 0;
}