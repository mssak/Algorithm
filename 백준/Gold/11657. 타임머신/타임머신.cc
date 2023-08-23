#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N + 1);
    vector<long long> dist(N + 1, LLONG_MAX);

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A].push_back({B, C});
    }

    dist[1] = 0;
    bool negativeCycle = false;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (auto &bus : adj[j]) {
                int next = bus.first;
                int time = bus.second;
                if (dist[j] != LLONG_MAX && dist[next] > dist[j] + time) {
                    dist[next] = dist[j] + time;
                    if (i == N) {
                        negativeCycle = true;
                    }
                }
            }
        }
    }

    if (negativeCycle) {
        cout << -1;
    } else {
        for (int i = 2; i <= N; i++) {
            cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << '\n';
        }
    }

    return 0;
}
