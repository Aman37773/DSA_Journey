#include<iostream>
#include<iomanip>
using namespace std;
void value(int n,string *arr);
int main(){
int n;
string arr[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
cout<<"enter n: ";
cin>>n;
value(n,arr);
return 0;
}
void value(int n,string *arr){
if(n==0){
return;
}
int b=n%10;
n=n/10;
value(n,arr);
cout<<arr[b]<<"\t";
return;
}