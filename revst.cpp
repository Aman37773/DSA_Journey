#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;
void value(stack<int> &a,int *arr,int i,int &j){
if(a.empty()==1){
    return;
}
arr[i]=a.top();
i++;
a.pop();
value(a,arr,i,j);
a.push(arr[j]);
j++;
return;
}
int main(){
 int capacity,data,arr[100],i=0,j=0;
stack<int> a;
cout<<"enter capacity: ";
cin>>capacity;
cout<<"enter data: ";
for(int i=0;i<capacity;i++){
    cin>>data;
    a.push(data);
}
value(a,arr,i,j);
while(a.empty()!=1){
    cout<<a.top()<<"\n";
    a.pop();
}
return 0;
}