#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class student;
class child{
  public:
int value(student a);
};
class student{
int age=7;
friend int child::value(student a);
};

int child::value(student a){
cout<<a.age;
}
int main(){
  student a;
child b;
b.value(a);
return 0;
}