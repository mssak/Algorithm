#include <bits/stdc++.h>
#define FASTIO ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

using namespace std;

const int MAX = 1001;
const int INF = 987654321;

int n, m;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int dist[MAX][MAX][2];
bool board[MAX][MAX];

int bfs() {
    queue<tuple<int,int,int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int wall = get<2>(q.front());
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            if (board[ny][nx] == 0 && dist[ny][nx][wall] == INF) {
                dist[ny][nx][wall] = dist[y][x][wall] + 1;
                q.push({ny, nx, wall});
            }

            if (wall == 0 && board[ny][nx] == 1) {
                dist[ny][nx][wall+1] = dist[y][x][wall] + 1;
                q.push({ny, nx, wall+1});
            }
        }
    }

    int ret = min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
    return (ret == INF ? -1 : ret);
}

int main() {
    FASTIO;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            board[i][j] = c - '0';
            dist[i][j][0] = dist[i][j][1] = INF;
        }
    }

    cout << bfs() << endl;
    return 0;
}
