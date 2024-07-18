#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class student;
class child{
  public:
int value(student a);
int shall(student a);
int got(){
    cout<<"hello";
}
};
class student{
int age=7;
int marks=99;
friend class child;
};
int child::value(student a){
cout<<a.age<<endl;
}
int child::shall(student a){
cout<<a.marks<<endl;
}
int main(){
  student a;
child b;
b.value(a);
b.shall(a);
b.got();
return 0;
}