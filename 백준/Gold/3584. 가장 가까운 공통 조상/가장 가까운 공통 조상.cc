#include<bits/stdc++.h>
#define MAX 10'001
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin>>T;

    while(T--){
        int p[MAX]{0};
        vector<int> ch[MAX];
        int depth[MAX]{0};

        int n;
        cin>>n;

        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            p[b]=a;
            ch[a].push_back(b);
        }

        int r;
        for(int i=1;i<=n;i++){
            if(!p[i]){
                r=i;
                break;
            }
        }

        stack<pair<int,int>> s;
        s.push({r,1});

        while(s.size()){
            auto [c,d]=s.top();
            s.pop();
            depth[c]=d;

            for(int i:ch[c]){
                if(!depth[i]){
                    s.push({i,d+1});
                }
            }
        }

        int oa,ob;
        cin>>oa>>ob;

        if(depth[oa]>depth[ob]){
            while(depth[oa]!=depth[ob]){
                oa=p[oa];
            }
        }
        else{
            while(depth[oa]!=depth[ob]){
                ob=p[ob];
            }
        }

        while(oa!=ob){
            oa=p[oa];
            ob=p[ob];
        }

        cout<<oa<<"\n";
    }
}
