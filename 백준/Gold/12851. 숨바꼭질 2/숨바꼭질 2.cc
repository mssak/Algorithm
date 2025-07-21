#include<bits/stdc++.h>
#define MAX 100'002
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;

    vector<int> v(MAX,-1);
    queue<pii> q;
    q.push({n,0});
    v[n]=0;

    int ans=0;
    while(q.size()){
        auto [cn,cd]=q.front();
        q.pop();
        if(cn==k){
            ans++;
            continue;
        }

        for(int nn:{cn+1,cn-1,cn*2}){
            int nd=cd+1;
            if(nn>=0&&nn<MAX){
                if(v[nn]==-1||v[nn]==nd){
                    v[nn]=nd;
                    q.push({nn,nd});
                }
            }
        }
    }

    cout<<v[k]<<" "<<ans;
}