#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    map<int, int> m; // a를 key로, b를 value로 사용합니다.
    
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(m.find(a) == m.end() || m[a] < b) { // a가 아직 map에 없거나, 존재하는 b 값보다 큰 경우 업데이트
            m[a] = b;
        }
    }

    int l,p,ans{0};
    cin>>l>>p;

    priority_queue<int> pq;
    auto it = m.begin();
    
    while(true){
        if(l<=p){
            cout<<ans;
            return 0;
        }

        for(; it != m.end() && it->first <= p; ++it){
            pq.push(it->second);
        }

        if(!pq.empty()){
            // cout<<pq.top()<<" ";
            p+=pq.top();
            pq.pop();
            // cout<<p<<"\n";
            ans++;
        }
        else{
            cout<<-1;
            return 0;
        }
    }
}
