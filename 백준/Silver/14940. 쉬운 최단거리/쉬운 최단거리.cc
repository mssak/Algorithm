#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int arr[MAX][MAX];
    int v[MAX][MAX];
    memset(v, -1, sizeof(v));  // 방문 여부 및 거리를 -1로 초기화

    int sy, sx;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                sy = i;
                sx = j;
            } else if (arr[i][j] == 0) {
                v[i][j] = 0;  // 갈 수 없는 땅은 0으로 설정
            }
        }
    }

    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    queue<tuple<int, int, int>> q;
    q.push({sy, sx, 0});
    v[sy][sx] = 0;

    while (!q.empty()) {
        auto [cy, cx, cd] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cy + dir[i][0];
            int nx = cx + dir[i][1];
            int nd = cd + 1;

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && v[ny][nx] == -1 && arr[ny][nx] == 1) {
                v[ny][nx] = nd;
                q.push({ny, nx, nd});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 && v[i][j] == -1) {
                cout << -1 << " ";
            } else {
                cout << v[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
