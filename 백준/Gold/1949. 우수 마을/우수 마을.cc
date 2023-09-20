#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MAX_N = 10005;

int N, C[MAX_N];
vector<int> adj[MAX_N];
int dp[MAX_N][2];

void f(int x, int par)
{
    dp[x][1] = C[x];
    for(int nxt : adj[x]){
        if(nxt == par) continue;
        f(nxt, x);
        dp[x][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[x][1] += dp[nxt][0];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> C[i];
    for(int i=0; i<N-1; i++){
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    f(1, 0);
    printf("%d\n", max(dp[1][1], dp[1][0]));
    return 0;
}
