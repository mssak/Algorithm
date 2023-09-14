#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

typedef pair<int, int> pii;

struct Edge {
    int from, to;
    double weight;

    bool operator<(const Edge &other) const {
        return weight > other.weight; // 우선순위 큐를 위해 큰 것부터 pop되게 함
    }
};

double getDistance(const pii &a, const pii &b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double prim(int N, vector<vector<Edge>>& adj) {
    vector<bool> visited(N, false);
    priority_queue<Edge> pq;
    pq.push({0, 0, 0.0});
    double answer = 0.0;

    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();

        if (visited[cur.to]) continue;
        visited[cur.to] = true;
        answer += cur.weight;

        for (Edge next : adj[cur.to]) {
            if (!visited[next.to]) {
                pq.push(next);
            }
        }
    }

    return answer;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pii> coords(N);
    for (int i = 0; i < N; i++) {
        cin >> coords[i].first >> coords[i].second;
    }

    vector<vector<Edge>> adj(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double dist = getDistance(coords[i], coords[j]);
            adj[i].push_back({i, j, dist});
            adj[j].push_back({j, i, dist});
        }
    }

    while (M--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back({a, b, 0.0});
        adj[b].push_back({b, a, 0.0});
    }

    cout << fixed << setprecision(2) << prim(N, adj) << "\n";

    return 0;
}
