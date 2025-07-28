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

    // 미리 2개의 격자(grid)를 생성
    vector<vector<int>> grid1(n, vector<int>(m));
    vector<vector<int>> grid2(n, vector<int>(m));

    int cu = -1;
    int cd;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // 초기 상태는 grid1에 저장
            cin >> grid1[i][j];
            if(grid1[i][j] == -1){
                if(cu == -1){
                    cu = i;
                } else {
                    cd = i;
                }
            }
        }
    }

    // 포인터를 사용해 현재 상태 격자와 다음 상태 격자를 가리킴
    vector<vector<int>>* current_grid = &grid1;
    vector<vector<int>>* next_grid = &grid2;

    int dy[4] = {0, -1, 0, 1};
    int dx[4] = {1, 0, -1, 0};

    while(t--){
        // 1. 다음 상태를 계산하기 전에 next_grid를 0으로 초기화
        for(int i = 0; i < n; ++i) {
            fill((*next_grid)[i].begin(), (*next_grid)[i].end(), 0);
        }

        // 2. 확산 (current_grid를 읽어서 next_grid에 결과를 씀)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((*current_grid)[i][j] > 0){
                    int spreadCnt = 0;
                    int tospread = (*current_grid)[i][j] / 5;
                    for(int d = 0; d < 4; d++){
                        int ny = i + dy[d];
                        int nx = j + dx[d];
                        if(ny >= 0 && ny < n && nx >= 0 && nx < m && (*current_grid)[ny][nx] != -1){
                            (*next_grid)[ny][nx] += tospread;
                            spreadCnt++;
                        }
                    }
                    (*next_grid)[i][j] += (*current_grid)[i][j] - spreadCnt * tospread;
                }
            }
        }
        (*next_grid)[cu][0] = -1;
        (*next_grid)[cd][0] = -1;

        // 3. 공기청정기 작동 (확산이 완료된 next_grid에 직접 적용)
        // up clean
        for(int y = cu - 2; y >= 0; y--){
            (*next_grid)[y + 1][0] = (*next_grid)[y][0];
        }
        for(int x = 1; x < m; x++){
            (*next_grid)[0][x - 1] = (*next_grid)[0][x];
        }
        for(int y = 1; y <= cu; y++){
            (*next_grid)[y - 1][m - 1] = (*next_grid)[y][m - 1];
        }
        for(int x = m - 2; x > 0; x--){
            (*next_grid)[cu][x + 1] = (*next_grid)[cu][x];
        }
        (*next_grid)[cu][1] = 0;

        // down clean
        for(int y = cd + 2; y < n; y++){
            (*next_grid)[y - 1][0] = (*next_grid)[y][0];
        }
        for(int x = 1; x < m; x++){
            (*next_grid)[n - 1][x - 1] = (*next_grid)[n - 1][x];
        }
        for(int y = n - 2; y >= cd; y--){
            (*next_grid)[y + 1][m - 1] = (*next_grid)[y][m - 1];
        }
        for(int x = m - 2; x > 0; x--){
            (*next_grid)[cd][x + 1] = (*next_grid)[cd][x];
        }
        (*next_grid)[cd][1] = 0;

        // 4. 포인터 교체. 다음 루프에서는 역할이 바뀜
        swap(current_grid, next_grid);
    }

    int ans = 0;
    // 최종 결과는 current_grid에 저장되어 있음
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((*current_grid)[i][j] != -1){
                ans += (*current_grid)[i][j];
            }
        }
    }
    cout << ans;
}