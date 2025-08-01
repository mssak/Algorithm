#include<bits/stdc++.h>
using namespace std;main(){string s;cin>>s;sort(s.rbegin(),s.rend());cout<<(s.back()==48&&accumulate(s.begin(),s.end(),0)%3==0?s:"-1");}