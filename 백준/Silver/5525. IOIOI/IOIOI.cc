#include<bits/stdc++.h>
#define MAX 101
using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;

    int ans=0;
    int cnt=0;
    bool st=s[0]=='I'?1:0;

    for(int i=1;i<m;i++){
        char c=s[i];
        char bef=s[i-1];
        if(st){
            if(bef==c){
                int tmp=cnt+1-n;
                if(tmp>0){
                    ans+=tmp;
                }
                cnt=0;
                
                if(c=='I'){
                    st=1;
                }else{
                    st=0;
                }
            }else{
                if(c=='I'){
                    cnt++;
                }
            }
        }else{
            if(c=='I'){
                st=1;
            }
        }
    }
    int tmp=cnt+1-n;
    if(tmp>0){
        ans+=tmp;
    }

    cout<<ans;
}