#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC;

    while (TC--) {
        int N, M, W;
        cin >> N >> M >> W;

        vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

        for (int i = 1; i <= N; i++) {
            dist[i][i] = 0;
        }

        // 도로 정보 입력
        for (int i = 0; i < M; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            if(T < dist[S][E]) { // 더 작은 값으로 갱신
                dist[S][E] = T;
                dist[E][S] = T;
            }
        }

        // 웜홀 정보 입력
        for (int i = 0; i < W; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            if(-T < dist[S][E]) { // 더 작은 값으로 갱신
                dist[S][E] = -T;
            }
        }

        // 플로이드 워셜 알고리즘
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        bool timeTravel = false;
        for (int i = 1; i <= N; i++) {
            if (dist[i][i] < 0) {
                timeTravel = true;
                break;
            }
        }

        if (timeTravel) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
