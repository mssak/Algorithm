#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string a,string b)
{
    if(a.size()==b.size()){
        return a<b;
    }
    else{
        return a.size()<b.size();
    }

}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a;
    cin>>a;


    vector<string> v;
    v.reserve(20000);
    string s;

    for(int i=0;i<a;i++){
        cin>>s;
        v.push_back(s);
    }

    sort(v.begin(),v.end(),compare);
    for(int i=0;i<a;i++){
        if(i>0&&v[i-1]==v[i]){
            continue;
        }
        else{
            cout<<v[i]<<"\n";
        }
    }
}