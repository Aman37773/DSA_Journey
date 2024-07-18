#include<iostream>
#include<iomanip>
#include<deque>
using namespace std;
int check(deque<int> pet,deque<int> dis,int value){
    if(pet.empty()){
        return 1;
    }
if(value+pet.front()>=dis.front()){
    value=value+pet.front()-dis.front();
    pet.pop_front();
    dis.pop_front();
  int get=check(pet,dis,value);
return get;
}
else{
return 0;
}
}
int main(){
int n,d[100],p[100],value=0;
deque<int> pet,dis;
cout<<"enter n: ";
cin>>n;
cout<<"enter petrol for each: ";
for(int i=0;i<n;i++){
    cin>>p[i];
    pet.push_back(p[i]);
}
cout<<"enter distance for each: ";
for(int i=0;i<n;i++){
    cin>>d[i];
    dis.push_back(d[i]);
}
for(int i=0;i<n;i++){
int got=check(pet,dis,value);
if(got==1){
    cout<<i<<"\t";
}
pet.push_back(pet.front());
dis.push_back(dis.front());
pet.pop_front();
dis.pop_front();
}
return 0;
}