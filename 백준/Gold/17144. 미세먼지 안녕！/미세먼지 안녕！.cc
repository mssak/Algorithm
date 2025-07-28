#include<bits/stdc++.h>
#define MAX 51
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, t;
    cin >> n >> m >> t;

    // 1. 크기 2의 격자 배열과 플래그 변수 선언
    vector<vector<int>> grids[2];
    grids[0].assign(n, vector<int>(m));
    grids[1].assign(n, vector<int>(m));
    int flag = 0;

    int cu = -1;
    int cd;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // 초기 상태는 grids[0]에 저장
            cin >> grids[0][i][j];
            if(grids[0][i][j] == -1){
                if(cu == -1){
                    cu = i;
                } else {
                    cd = i;
                }
            }
        }
    }

    int dy[4] = {0, -1, 0, 1};
    int dx[4] = {1, 0, -1, 0};

    while(t--){
        // 현재 상태와 다음 상태의 인덱스 결정
        int current_idx = flag;
        int next_idx = 1 - flag;

        // 다음 상태 격자(next_grid) 초기화
        for(int i = 0; i < n; ++i) {
            fill(grids[next_idx][i].begin(), grids[next_idx][i].end(), 0);
        }
        
        // 확산 (current에서 읽어서 next에 쓰기)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grids[current_idx][i][j] > 0){
                    int spreadCnt = 0;
                    int tospread = grids[current_idx][i][j] / 5;
                    for(int d = 0; d < 4; d++){
                        int ny = i + dy[d];
                        int nx = j + dx[d];
                        if(ny >= 0 && ny < n && nx >= 0 && nx < m && grids[current_idx][ny][nx] != -1){
                            grids[next_idx][ny][nx] += tospread;
                            spreadCnt++;
                        }
                    }
                    grids[next_idx][i][j] += grids[current_idx][i][j] - spreadCnt * tospread;
                }
            }
        }
        grids[next_idx][cu][0] = -1;
        grids[next_idx][cd][0] = -1;

        // 공기청정기 작동 (next 격자에 직접 적용)
        // up clean
        for(int y = cu - 2; y >= 0; y--){
            grids[next_idx][y + 1][0] = grids[next_idx][y][0];
        }
        for(int x = 1; x < m; x++){
            grids[next_idx][0][x - 1] = grids[next_idx][0][x];
        }
        for(int y = 1; y <= cu; y++){
            grids[next_idx][y - 1][m - 1] = grids[next_idx][y][m - 1];
        }
        for(int x = m - 2; x > 0; x--){
            grids[next_idx][cu][x + 1] = grids[next_idx][cu][x];
        }
        grids[next_idx][cu][1] = 0;

        // down clean
        for(int y = cd + 2; y < n; y++){
            grids[next_idx][y - 1][0] = grids[next_idx][y][0];
        }
        for(int x = 1; x < m; x++){
            grids[next_idx][n - 1][x - 1] = grids[next_idx][n - 1][x];
        }
        for(int y = n - 2; y >= cd; y--){
            grids[next_idx][y + 1][m - 1] = grids[next_idx][y][m - 1];
        }
        for(int x = m - 2; x > 0; x--){
            grids[next_idx][cd][x + 1] = grids[next_idx][cd][x];
        }
        grids[next_idx][cd][1] = 0;

        // 2. 포인터 스왑 대신 flag 값을 변경
        flag = 1 - flag;
    }

    int ans = 0;
    // 3. 최종 결과는 grids[flag]에 저장되어 있음
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grids[flag][i][j] != -1){
                ans += grids[flag][i][j];
            }
        }
    }
    cout << ans;
}