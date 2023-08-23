#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;

bool updateDist(vector<vector<pll>> &edge, long long dist[], int n) {
    bool updated = false;
    for (int j = 1; j <= n; j++) {
        for (auto k : edge[j]) {
            auto [d, v] = k;
            if (dist[j] == LLONG_MAX) continue;
            if (dist[v] > dist[j] + d) {
                dist[v] = dist[j] + d;
                updated = true;
            }
        }
    }
    return updated;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<pll>> edge(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edge[a].push_back({c, b});
    }

    long long dist[n + 1];
    fill(dist, dist + n + 1, LLONG_MAX);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i++) {
        updateDist(edge, dist, n);
    }

    if (updateDist(edge, dist, n)) {
        cout << -1;
        return 0;
    }

    for (int i = 2; i < n + 1; i++) {
        cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << "\n";
    }
}
