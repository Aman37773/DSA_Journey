#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class student{
    public:
int  age=9;
char *ptr;
//int value(int age){
//(*this).age=age;
//}
student(char *got,int value){
(*this).ptr=got;
(*this).age=value;
}
student(student &temp){
char *ppptr=new char[strlen(temp.ptr)+1]; 
strcpy(ppptr,temp.ptr);
(*this).ptr=ppptr;
}
};
int main(){
char name[]="aman";
student a(name,7);
student b(a);
a.ptr[0]='y';
//student *ptr=new student[3];
cout<<b.ptr<<endl;
//cout<<b.name;

return 0;
}