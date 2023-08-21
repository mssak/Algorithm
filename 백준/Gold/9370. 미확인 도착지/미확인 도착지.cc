#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int T, n, m, t, s, g, h, a, b, d;

vector<pair<int, int>> graph[2001];
int candidate[100];

void dijkstra(int start, vector<int>& distance) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty()) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (distance[now] < dist) continue;

        for (auto& i : graph[now]) {
            int cost = dist + i.second;
            if (cost < distance[i.first]) {
                distance[i.first] = cost;
                pq.push({cost, i.first});
            }
        }
    }
}

int main() {
    cin >> T;

    while (T--) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        for (int i = 1; i <= n; i++) {
            graph[i].clear();
        }

        int ghDist = 0;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> d;
            graph[a].push_back({b, d});
            graph[b].push_back({a, d});
            if ((a == g && b == h) || (a == h && b == g)) ghDist = d;
        }

        for (int i = 0; i < t; i++) {
            cin >> candidate[i];
        }

        vector<int> distanceFromS(n + 1, INF);
        vector<int> distanceFromG(n + 1, INF);
        vector<int> distanceFromH(n + 1, INF);

        dijkstra(s, distanceFromS);
        dijkstra(g, distanceFromG);
        dijkstra(h, distanceFromH);

        vector<int> result;
        for (int i = 0; i < t; i++) {
            int x = candidate[i];
            if (distanceFromS[g] + ghDist + distanceFromH[x] == distanceFromS[x] ||
                distanceFromS[h] + ghDist + distanceFromG[x] == distanceFromS[x]) {
                result.push_back(x);
            }
        }

        sort(result.begin(), result.end());
        for (int x : result) {
            cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}
