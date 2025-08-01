#include<bits/stdc++.h>
using namespace std;int main(){string s;cin>>s;sort(s.begin(),s.end(),greater<>());cout<<(s.back()=='0'&&accumulate(s.begin(),s.end(),0)%3==0?s:"-1");}