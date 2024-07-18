#include<iostream>
#include<iomanip>
#include<queue>
#include<string>
using namespace std;
int travel(queue<char> c,char tra,int m){
    if(c.empty()==1){
        if(m==1){
            return 1;
        }
        else{
            return 0;
        }
    }
if(c.front()==tra){
    ++m;
}
c.pop();
int value=travel(c,tra,m);
return value;
}


void check(queue<char> b,queue<char> c,int m){
    if(b.empty()){
        cout<<'#';
        return;
    }
char tra=b.front();
b.pop();
int get=travel(c,tra,m);
if(get==0){
    check(b,c,m);
    return;
}
else{
cout<<tra;
return;
}
}

int main(){
string a;
queue<char> b;
queue<char> c;
int n,m=0;
cout<<"enter string size: ";
cin>>n;
cout<<"enter string: ";
cin>>a;
for(int i=0;i<n;i++){
    b.push(a[i]);
    c.push(a[i]);
    check(b,c,m);
}
return 0;
}