#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;
    
    while(N--){
        string s;
        cin>>s;
        string ans{s};
        if(next_permutation(s.begin(),s.end())){
            cout<<s<<"\n";
        }
        else{
            cout<<ans<<"\n";
        }
    }
}