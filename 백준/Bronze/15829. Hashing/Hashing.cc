#include<bits/stdc++.h>
#define MAX 
using namespace std;
using ll = long long;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    string s;
    cin>>n>>s;

    long long a=0;
    for(int i=0;i<n;i++){
        a+=(s[i]-'a'+1)*pow(31,i);
        a%=1234567891;
    }
    cout<<a;
}
