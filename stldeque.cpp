#include<iostream>
#include<iomanip>
#include<deque>
using namespace std;
int main(){
deque<int> a;
a.push_front(6);    // 9 6 90 900 
a.push_front(9);    // fr      back
a.push_back(90);
a.push_back(900);
a.pop_front();
a.pop_front();
a.pop_front();
cout<<a.front();
return 0;
}