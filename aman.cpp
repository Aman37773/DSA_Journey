#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main(){
    vector<int>v;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    const int N=1e5+10;
    vector<int>freq(N,0);
    for(int i=0;i<n;i++){
        freq[v[i]]++;
    }
    cout<<"enter the queries";
    int q;
    cin>>q;
    while(q--){
        int queryelement;
        cin>>queryelement;
        cout<<freq[queryelement]<<endl;
    
    }
    return 0;
}