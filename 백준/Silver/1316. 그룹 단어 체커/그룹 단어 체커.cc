#include<iostream>
using namespace std;

bool isGroup(string s){
    bool flag,alp[26]={false};
    char before;
    for(int j=0;j<s.size();j++){
        // cout<<s[j]<<endl;
        if(s[j-1]!=s[j]&&alp[s[j]-97]==true){
            // cout<<"false"<<endl;
            return false;
        }
        alp[s[j]-97]=true;
    }
    return true;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,answer=0;
    cin>>a;

    string s;
    for(int i=0;i<a;i++){
        cin>>s;
        if(isGroup(s)) answer+=1;
    }
    cout<<answer;
}
