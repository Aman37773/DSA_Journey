#include<iostream>
#include<iomanip>
#include <cstdio>
#include<string>
#include<fstream>
using namespace std;
int main(){
FILE *ptr;
//ptr=fopen("ner.txt","a");
//fprintf(ptr,"%s"," lolypop");

ptr=fopen("nep.txt","r");
   
   char c;

   while(  (c= fgetc(ptr))!=EOF){
 
       printf("%c",c);
       
   }

 
     



return 0;
}

