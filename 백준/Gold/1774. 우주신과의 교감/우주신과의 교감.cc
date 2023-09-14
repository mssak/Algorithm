#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

typedef pair<int, int> pii;
typedef pair<double, int> pdi; // 우선순위 큐를 위한 타입 (거리, 인덱스)

double getDistance(const pii &a, const pii &b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double prim(int N, const vector<pii>& coords, const vector<vector<int>>& connected) {
    vector<bool> visited(N, false);
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq; // 거리가 작은 것부터 pop 되도록 설정
    pq.push({0.0, 0}); // 시작점
    double answer = 0.0;

    while (!pq.empty()) {
        double dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur]) continue;
        visited[cur] = true;
        answer += dist;

        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                if (find(connected[cur].begin(), connected[cur].end(), i) != connected[cur].end()) {
                    pq.push({0.0, i}); // 이미 연결된 통로
                } else {
                    pq.push({getDistance(coords[cur], coords[i]), i});
                }
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

    vector<vector<int>> connected(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        connected[a].push_back(b);
        connected[b].push_back(a);
    }

    cout << fixed << setprecision(2) << prim(N, coords, connected) << "\n";

    return 0;
}
