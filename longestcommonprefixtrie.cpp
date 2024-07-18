#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class trienode{
public:
trienode *children[26];
bool isempty;
trienode(){
    for(int i=0;i<26;i++){
        children[i]=NULL;
    }
    isempty=false;
}

void insert(trienode *root,string s){
    trienode *cur=root;
    for(int i=0;i<s.length();i++){
        if(cur->children[s[i]-'A']==NULL){
           cur->children[s[i]-'A']=new trienode();
        cur = cur->children[s[i]-'A'];
        }      
        else{
            cur = cur->children[s[i]-'A'];
        }

    }
    cur->isempty=true;
}

void longestprefix(trienode *root,string &ans){
    int m=0;
    char save;
    int index;
    while(1){
for(int i=0;i<26;i++){
    if(root->children[i]!=NULL){
        save=i+65;
        index=i;
        ++m;
    }
}
if(m==1){
    ans=ans+save;
    root=root->children[index];
    m=0;
}
else{
    return;
}
}
}
};



int main(){
trienode *root=new trienode();
(*root).insert(root,"CODING"); 
(*root).insert(root,"CODIZEN");  
(*root).insert(root,"CODINGNINJA"); 
(*root).insert(root,"CODIR"); 
string ans;
(*root).longestprefix(root,ans);
cout<<ans;
return 0;
}