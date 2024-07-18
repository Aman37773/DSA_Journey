#include<iostream>
#include<iomanip>
//#include<string>
using namespace std;
int main(){
string z="shot"; // normal string

//z="lol";
char *pptr=&z[0]; 
//const string z="lop";
//z="kol";
char age='9';
const char  *a;   //meaning of const char *a and const string
a="aman";
a="pop";
//a[1]='t';
//cout<<a[1];
cout<<pptr;
return 0;
}