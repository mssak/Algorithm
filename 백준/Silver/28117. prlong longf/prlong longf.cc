#include<bits/stdc++.h>
#define MAX 80
using namespace std;

int n;
string l="long";
string s;
int dp[21]{0};

int f(int a)
{
    if(dp[a]){
        return dp[a];
    }

    return dp[a]=f(a-1)+f(a-2);
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long ans{1};
    cin>>n>>s;

    dp[1]=1;
    dp[0]=1;

    int j=0;
    int c=0;

    f(20);
    for(int i=0; i<n; i++){
        if(i + 3 < n && s.substr(i, 4) == "long") c++, i += 3;
        else ans *= dp[c], c = 0;
    }
    ans*=dp[c];
    cout<<ans;
}
