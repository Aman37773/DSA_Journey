#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;
int main(){
string a;
stack<char> b;
cout<<"enter string: ";
cin>>a;
for(int i=0;i<a.length();i++){
    if(a[i]=='('||a[i]=='{'||a[i]=='['||a[i]=='+'||a[i]=='-'||a[i]=='/'||a[i]=='*'){
        b.push(a[i]);
    }
    else if(a[i]>='a'&&a[i]<='z'){
        continue;
    }
    else if(a[i]=='}'||a[i]==']'||a[i]==')'){
        if(b.top()=='+'||b.top()=='-'||b.top()=='/'||b.top()=='*'){
            while(b.top()!='('&&b.top()!='{'&&b.top()!='['){
                b.pop();
            }
            b.pop();
        }
        else{
            continue;
        }
    }
}
if(b.empty()==1){
    cout<<"no";
}
else{
    cout<<"yes";
}
return 0;
}