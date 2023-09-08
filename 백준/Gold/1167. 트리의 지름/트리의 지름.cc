#include<bits/stdc++.h>
#define MAX 100'001
using namespace std;
using pii=pair<int,int>;

vector<pii> tree[MAX];
int v;

pii dfs(int s)
{
    int dist[MAX];
    for(int i=0;i<=v;i++){
        dist[i]=-1;
    }
    dist[s]=0;

    stack<int> stk;
    stk.push(s);

    while(!stk.empty()){
        int c=stk.top();
        stk.pop();

        for(pii i:tree[c]){
            auto [n,d]=i;
            if(dist[n]==-1){
                dist[n]=dist[c]+d;
                stk.push(n);
            }
        }
    }

    int* m=max_element(dist,dist+v+1);
    return pii{m-dist,*m};
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>v;

    for(int i=0;i<v;i++){
        int a;
        cin>>a;
        while(true){
            int b,c;
            cin>>b;
            if(b==-1){
                break;
            }
            cin>>c;

            tree[a].emplace_back(b,c);
        }
    }

    pii x=dfs(1);
    pii y=dfs(x.first);

    cout<<y.second;
}
