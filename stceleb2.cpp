#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;
int main(){
int arr[100][100],size;
stack<int> a;
cout<<"entr size: ";
cin>>size;
cout<<"enter elements: ";
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        cin>>arr[i][j];
    }
}
for(int i=0;i<size;i++){
a.push(i);
}
while(a.size()!=1){
int val1=a.top();
a.pop();
int val2=a.top();
a.pop();
if(arr[val1][val2]==1&&arr[val2][val1]==0){
    a.push(val2);
}
else if(arr[val1][val2]==0&&arr[val2][val1]==1){
    a.push(val1);
}
else if(arr[val1][val2]==1&&arr[val2][val1]==1){
    continue;
}
}
cout<<a.top()<<"  is celebrity";
return 0;
}