#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main(){//3*2
int **ptr=new int*[3];
for(int i=0;i<3;i++){
ptr[i]=new int[2];
}
for(int i=0;i<3;i++){
for(int j=0;j<2;j++){
cin>>ptr[i][j];
}
}
cout<<**ptr<<endl;
ptr++;
cout<<**ptr<<endl;
ptr++;
cout<<**ptr<<endl;
ptr++;
cout<<**ptr<<endl;
ptr++;
cout<<**ptr<<endl;
return 0;
}