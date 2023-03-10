#include<bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    int n,a,b,d;
    cin>>n;

    while(n--){
        deque<pair<int,int>> dq;
        int imp[10]={};
        int ans=1;

        cin>>a>>d;
        for(int i=0;i<a;i++){
            cin>>b;
            imp[b]++;
            dq.push_back({i,b});
        }
        
        while(1){
            bool out=true;
            for(int i=dq[0].second+1;i<=9;i++){
                if(imp[i]!=0){
                    out=false;
                    break;
                }
            }
            if(out){
                if(dq[0].first==d){
                    cout<<ans<<"\n";
                    break;
                }
                else{
                    imp[dq.front().second]--;
                    dq.pop_front();
                    ans++;
                }
            }
            else{
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
}