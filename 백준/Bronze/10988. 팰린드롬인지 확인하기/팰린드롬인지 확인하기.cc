#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin>>s;
    int l = s.size();

    for(int i=0;i<=(l+1)/2;i++){
        if(s[i-1]!=s[l-i]){
            cout<<0;
            return 0;
        }
    }

    cout<<1;
}