#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int value(int n);
int main(){
int n,b;
cin>>n;
b=value(n);
cout<<b;
return 0;
}
int value(int n){
    if(n==0){
    return 0;
    }
cout<<n<<"\t";
return value(n-1);;
}