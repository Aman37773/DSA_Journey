#include<iostream>
#include<iomanip>
#include<string.h>
#include<cstdlib>
using namespace std;
int main(){
char *a;
//a="aman";
a=(char *)malloc(3*sizeof(char));
a[0]='1';
delete []a;
//int arr[]={1,2,3};
//cout<<sizeof(a);
cout<<a[2];

return 0;
}