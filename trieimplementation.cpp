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

bool search(trienode *root,string got){
trienode *cur=root;
for(int i=0;i<got.length();i++){
    if(cur->children[got[i]-'A']==NULL){
        return false;
    }
    cur=cur->children[got[i]-'A'];
}
if(cur->isempty==true){
return true;
}
else{
    return false;
}
}

void deleting(trienode *cur,trienode *prev,string get,int i){
if(i==get.length()){
cur->isempty=false;
int s=0;
for(int j=0;j<26;j++){
    if(cur->children[j]!=NULL){
        s=1;
        break;
    }
}
if(s==0&&cur->isempty==false){
    delete cur;
    prev->children[get[i-1]-'A']=NULL;
}
return;
}
deleting(cur->children[get[i]-'A'],cur,get,i+1);
int s=0;
for(int j=0;j<26;j++){
    if(cur->children[j]!=NULL){
        s=1;
        break;
    }
}
if(s==0&&cur->isempty==false){
    delete cur;
     prev->children[get[i-1]-'A']=NULL;
}
return;
}




};



int main(){
trienode *root=new trienode();
(*root).insert(root,"ABC"); 
(*root).insert(root,"AB");  //0(l) l->length of string 
(*root).deleting(root,root,"ABC",0) ; //0(l) l->length of string 
cout<<(*root).search(root,"AB");  //0(l)  l->length of string

return 0;
}