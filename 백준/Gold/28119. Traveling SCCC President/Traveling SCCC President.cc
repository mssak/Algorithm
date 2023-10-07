#include<bits/stdc++.h>
#define MAX 2000
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    bool v[MAX]{};
    int edge[MAX][MAX];
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            edge[i][j] = INT_MAX; 

    int n, m, s;
    cin >> n >> m >> s;
    s--;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edge[a][b] = edge[b][a] = min(edge[a][b], c);
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
    }

    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});

    while (pq.size()) {
        auto [d, c] = pq.top();
        pq.pop();
        if (v[c]) {
            continue;
        }
        ans += d;
        v[c] = true;
        for (int i = 0; i < n; i++) {
            if (v[i] || edge[c][i] == INT_MAX) {
                continue;
            }
            pq.push({edge[c][i], i});
        }
    }
    cout << ans;
}
