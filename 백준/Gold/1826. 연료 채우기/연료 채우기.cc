#include<bits/stdc++.h>
#define MAX 
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    vector<pair<int,int>> v;
    v.reserve(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());

    int l,p,ans{0};
    cin>>l>>p;

    priority_queue<int> pq;
    int i=0;
    while(l>p){
        for(;i<n && v[i].first<=p;i++){
            pq.push(v[i].second);
        }

        if(!pq.empty()){
            p+=pq.top();
            pq.pop();
            ans++;        
        }
        else{
            cout<<-1;
            return 0;
        }
    }
    cout<<ans;
}
