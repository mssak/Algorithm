#include <bits/stdc++.h>
#define MAX 500
using namespace std;

int M, N, H;
int arr[MAX][MAX];
int dp[MAX][MAX];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(int x, int y) {
    if (x == M - 1 && y == N - 1) {
        return 1;
    }

    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < M && ny < N && arr[nx][ny] < arr[x][y]) {
            dp[x][y] += dfs(nx, ny);
        }
    }

    return dp[x][y];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0) << '\n';

    return 0;
}
