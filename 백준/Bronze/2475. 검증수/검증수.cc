#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a,s=0;
    for(int i=0;i<5;i++){
      cin>>a;
      s+=a*a;
    }
    cout<<s%10;
}