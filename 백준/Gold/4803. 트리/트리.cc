#include<bits/stdc++.h>
#define MAX 501
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T{0};
    while(true){
        int n,m,ans{0};
        cin>>n>>m;
        if(n==0 && m==0){
            return 0;
        }
        T++;

        vector<int> edge[MAX];
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        bool v[MAX]={0,};

        for(int i=1;i<=n;i++){
            if(v[i]){
                continue;
            }

            stack<pair<int,int>> s;
            s.push({i,0});
            v[i]=true;
            bool cycle=false;
            while(!s.empty()){
                auto [c,p]=s.top();
                s.pop();

                for(int i:edge[c]){
                    if(i==p){
                        continue;
                    }
                    if(v[i]){
                        cycle=true;
                    }
                    else{
                        s.push({i,c});
                        v[i]=true;
                    }
                }
            }
            if(!cycle){
                ans++;
            }
        }

        if(ans==0){
            printf("Case %d: No trees.\n",T);
        }
        else if(ans==1){
            printf("Case %d: There is one tree.\n",T);
        }
        else{
            printf("Case %d: A forest of %d trees.\n",T,ans);
        }
    }
}