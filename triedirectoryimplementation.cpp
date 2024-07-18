#include<bits/stdc++.h>
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

void directory(trienode *root,int i,string &ans){
if(root->isempty==true){
        cout<<ans<<" ";
    }
for(int s=i;s<26;s++){
if(root->children[s]!=NULL){
    char get=s+65;
    ans=ans+get;
    directory(root->children[s],0,ans);
}
}
    ans.pop_back();
    return;




for(int s=i;s<26;s++){
if(root->children[s]!=NULL){
    char get=s+65;
    ans=ans+get;
    
    directory(root->children[s],0,ans);
}
}
    ans.pop_back();
    return;
}



};



int main(){
trienode *root=new trienode();
(*root).insert(root,"COD"); 
(*root).insert(root,"CODING");  
(*root).insert(root,"CODDING"); 
(*root).insert(root,"CODE"); 
(*root).insert(root,"COLY"); 
string prefix="CODING";

 string ans;
 trienode *cur=root;

for(int i=0;i<prefix.length();i++){
ans=ans+prefix[i];
cur=cur->children[prefix[i]-'A'];
 (*root).directory(cur,0,ans);
 ans=ans+prefix[i];
cout<<"\n";
}

return 0;
}