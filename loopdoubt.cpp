#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main(){
int i=0;
do{
cout<<i<<"\t";
i++;
if(i==5){
continue;
}
}
while(i<=5);
return 0;
}