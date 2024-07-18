#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int top=0;
void push(char *arr,char a,int i){
arr[i]=a;
return;
}
void pop(int &i){
--i;
return;
}
int main(){
    string a="aman";
char arr[100];
int i=0;
for(i=0;i<a.length();i++){
    push(arr,a[i],i);
}
--i;
while(i>=0){
cout<<arr[i];
pop(i);
}
return 0;
}