#include<bits/stdc++.h>
#define MAX 100'001
using namespace std;

int times[MAX]{0};
int pre[MAX];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;

    queue<tuple<int,int,int>> q;
    q.push({n,1,0});

    while(true){
        auto [c,t,p]=q.front();
        q.pop();

        if(times[c]){
            continue;
        }
        
        times[c]=t;
        pre[c]=p;

        if(c==k){
            break;
        }

        int dir[3];
        dir[0]=c-1;
        dir[1]=c+1;
        dir[2]=c*2;

        for(auto i:dir){
            if(i>=0 && i<MAX){
                q.push({i,t+1,c});
            }
        }
    }

    cout<<times[k]-1<<"\n";

    vector<int> ans;
    for(int i=k;i!=n;i=pre[i]){
        ans.push_back(i);
    }
    ans.push_back(n);
    
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
}
