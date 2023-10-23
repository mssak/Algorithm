#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin>>s;

    int ans=0,t=0;

    for(auto c:s){
        if(c=='('){
            t++;
        }
        else if(c==')'){
            if(t){
                t--;
            }
            else{
                ans++;
            }
        }
    }
    cout<<ans+t;
}