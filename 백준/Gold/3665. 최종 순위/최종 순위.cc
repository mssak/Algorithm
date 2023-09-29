#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n;

        vector<int> last_rank(n);
        vector<vector<int>> graph(n);
        vector<int> in_degree(n, 0);

        for (int i = 0; i < n; ++i) {
            cin >> last_rank[i];
            --last_rank[i];  // 1-based to 0-based index
        }

        // 기존 순위 정보를 그래프에 추가
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                graph[last_rank[i]].push_back(last_rank[j]);
                ++in_degree[last_rank[j]];
            }
        }

        cin >> m;

        // 순위가 바뀐 팀 정보를 업데이트
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            --a, --b;  // 1-based to 0-based index

            // 간선 방향을 바꿔주고, in_degree를 업데이트
            if (find(graph[a].begin(), graph[a].end(), b) != graph[a].end()) {
                graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
                --in_degree[b];
                graph[b].push_back(a);
                ++in_degree[a];
            } else {
                graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());
                --in_degree[a];
                graph[a].push_back(b);
                ++in_degree[b];
            }
        }

        // 위상 정렬
        queue<int> q;
        vector<int> result;

        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            if (q.size() > 1) {
                // 불확실한 경우
                cout << "?\n";
                goto END;
            }

            int current = q.front();
            q.pop();

            result.push_back(current);

            for (int next : graph[current]) {
                --in_degree[next];
                if (in_degree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (result.size() == n) {
            for (int team : result) {
                cout << team + 1 << " ";
            }
            cout << "\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }

        END:
        continue;
    }

    return 0;
}
