#include<bits/stdc++.h>

using namespace std;

void left(deque<int> &dq)
{
    dq.push_back(dq.front());
    dq.pop_front();
}

void right(deque<int> &dq)
{
    dq.push_front(dq.back());
    dq.pop_back();
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    deque<int> dq,dql,dqr;
    int a,b,c,ans=0;
    cin>>a>>b,c;
    for(int i=1;i<=a;i++){
        dq.push_back(i);
    }

    while(b--){
        cin>>c;

        dql = deque<int>(dq.begin(),dq.end());
        int l=0;
        while(dql[0]!=c){
            left(dql);
            l++;
        }

        dqr = deque<int>(dq.begin(),dq.end());
        int r=0;
        while(dqr[0]!=c){
            right(dqr);
            r++;
        }
        if(l<r){
            dq = deque<int>(dql.begin(),dql.end());
            dq.pop_front();
            ans+=l;
        }
        else{
            dq = deque<int>(dqr.begin(),dqr.end());
            dq.pop_front();
            ans+=r;
        }
    }
    cout<<ans;
}