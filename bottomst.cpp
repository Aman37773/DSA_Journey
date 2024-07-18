#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;
void value(stack<int> &a,int insert){
    if(a.empty()==1){
        a.push(insert);
        return;
    }
    int num=a.top();
    a.pop();
    value(a,insert);
a.push(num);
}
int main(){
    int capacity,data,insert;
stack<int> a;
cout<<"enter capacity: ";
cin>>capacity;
cout<<"enter data: ";
for(int i=0;i<capacity;i++){
    cin>>data;
    a.push(data);
}
cout<<"enter data to insert: ";
cin>>insert;
value(a,insert);
while(a.size()){
    cout<<a.top()<<"\n";
a.pop();
}
return 0;
}