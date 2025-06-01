#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;

    unordered_set<string> us;

    while(n--){
        string s;
        cin>>s;

        int ssize=s.size();
        for(int i=0;i<ssize;i++){
            string subs=s.substr(i);
            if(us.find(subs)==us.end()){
                us.insert(subs);
            }else{
                us.erase(subs);
            }
        }
    }

    cout<<us.size();

}
