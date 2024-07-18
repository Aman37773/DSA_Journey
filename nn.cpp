#include<iostream>
#include<iomanip>
#include<vector>
#include<math.h>
using namespace std;
int main(){
int n; 
cin>>n; 
vector<char>v; 
for(int i=0; i<n; i++){
    int k; 
    cin>>k; 
    char r=char(k) ;
    v.push_back(r);

}
for(int i=0; i<n; i++) cout<<v[i]<<" ";
cout<<endl;
return 0;
}