#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int value(int tot,int count,char char1,char char2,int end1,int end2);
int main(){
char arr[10];
cout<<"enter two digit string(2-9): ";//97 to 122  //char 1==num 49
cin>>arr;
int i=0,tot=0,end1=3,end2=3;
int m,n,map1,map2,count=0;
char char1,char2;
m=arr[0];
m=m-48;
n=arr[1];
n=n-48;
if(m==7||m==9){
end1=4;
}
if(n==7||n==9){
end2=4;
}
if(m>7){
map1=(m-2)*3+97+1;
}
else{
map1=(m-2)*3+97;
}
if(n>7){
map2=(n-2)*3+97+1;
}
else{
map2=(n-2)*3+97;
}
char1=map1;
char2=map2;
value(tot,count,char1,char2,end1,end2);
return 0;
}
int value(int tot,int count,char char1,char char2,int end1,int end2){
if(count==end2){
count=0;
char1++;
for(int k=0;k<end2;k++){
char2--;
}
tot++;
}
if(tot==end1){
return 0;
}
cout<<char1;
cout<<char2<<endl;
char2++;
count++;
value(tot,count,char1,char2,end1,end2);
return 0;
}