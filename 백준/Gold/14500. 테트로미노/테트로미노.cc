#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int max_sum = 0;
int max_val = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dx_opt[] = {0, 1, -1};
int dy_opt[] = {1, 0, 0};

void check_T_shape(int x, int y) {
    if (x >= 1 && x < N - 1 && y >= 1) {
        max_sum = max(max_sum, grid[x][y] + grid[x-1][y] + grid[x+1][y] + grid[x][y-1]);
    }
    if (x >= 1 && x < N - 1 && y < M - 1) {
        max_sum = max(max_sum, grid[x][y] + grid[x-1][y] + grid[x+1][y] + grid[x][y+1]);
    }
    if (x >= 1 && y >= 1 && y < M - 1) {
        max_sum = max(max_sum, grid[x][y] + grid[x-1][y] + grid[x][y-1] + grid[x][y+1]);
    }
    if (x < N - 1 && y >= 1 && y < M - 1) {
        max_sum = max(max_sum, grid[x][y] + grid[x+1][y] + grid[x][y-1] + grid[x][y+1]);
    }
}

void dfs(int x, int y, int depth, int sum) {
    if (sum + max_val * (4 - depth) <= max_sum) {
        return;
    }

    if (depth == 4) {
        max_sum = max(max_sum, sum);
        return;
    }

    for (int i = 0; i < 3; ++i) {
        int nx = x + dx_opt[i];
        int ny = y + dy_opt[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, depth + 1, sum + grid[nx][ny]);
            visited[nx][ny] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    grid.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
            max_val = max(max_val, grid[i][j]);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            visited[i][j] = true;
            dfs(i, j, 1, grid[i][j]);
            visited[i][j] = false;
            
            check_T_shape(i, j);
        }
    }

    cout << max_sum << endl;

    return 0;
}