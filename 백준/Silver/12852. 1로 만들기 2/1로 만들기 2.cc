#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    vector<bool> dp(n+1);

    queue<vector<int>> q;
    q.push({n});

    while(true){
        auto cv=q.front();
        q.pop();
        int c=cv.back();

        if(c==1){
            cout<<cv.size()-1<<"\n";
            for(auto i:cv){
                cout<<i<<" ";
            }
            return 0;
        }
        else if(dp[c]){
            continue;
        }

        dp[c]=true;

        if(c%3==0 && !dp[c/3]){
            vector<int> v(cv);
            v.push_back(c/3);
            q.push(v);
        }
        if(c%2==0 && !dp[c/2]){
            vector<int> v(cv);
            v.push_back(c/2);
            q.push(v);
        }
        if(c-1>0 && !dp[c-1]){
            vector<int> v(cv);
            v.push_back(c-1);
            q.push(v);
        }
    }
}
