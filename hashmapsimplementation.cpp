#include<iostream>
#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;
int main(){
    pair<string,int> a("moon",0);
   // cout<<a.second;
// unordered_map<string,int> m;
// m["lo"]=6;
// cout<<m["lol"];
map<string,int> g;
g["hello"]=8;
g["do"]=7;
// for(auto i=g.begin();i!=g.end();i++){
//     cout<<i->first;
// }
// for(auto i:g){
//     cout<<i.first<<" "<<i.second;
// }
map<string,int>::iterator it=g.begin();
while(it!=g.end()){
    cout<<it->first<<" "<<it->second;
    ++it;
}

return 0;
}