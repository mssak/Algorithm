#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> storage, vector<string> requests) {
    int n = storage.size();        // 세로 크기
    int m = storage[0].size();     // 가로 크기

    // 요청을 순서대로 처리합니다.
    for (const auto &req : requests) {
        char c = req[0]; // 요청 컨테이너 종류
        
        // 크레인 요청: 모든 해당 컨테이너 제거
        if (req.size() == 2) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (storage[i][j] == c) {
                        storage[i][j] = ' ';
                    }
                }
            }
        }
        // 지게차 요청: 요청 당시 외부와 연결된 컨테이너만 제거
        else {
            // 패딩을 추가한 grid 생성 (크기: (n+2) x (m+2))
            vector<string> pad(n + 2, string(m + 2, ' '));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    pad[i + 1][j + 1] = storage[i][j];
                }
            }
            
            // 외부(패딩판의 경계)에서부터 빈 칸(' ')만을 따라 BFS 진행
            vector<vector<bool>> visited(n + 2, vector<bool>(m + 2, false));
            queue<pair<int, int>> q;
            q.push({0, 0});
            visited[0][0] = true;
            int dy[4] = {-1, 1, 0, 0};
            int dx[4] = {0, 0, -1, 1};
            
            while (!q.empty()) {
                auto [y, x] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int ny = y + dy[k], nx = x + dx[k];
                    if (ny < 0 || ny >= n + 2 || nx < 0 || nx >= m + 2) continue;
                    if (visited[ny][nx]) continue;
                    // 오직 빈 칸인 경우만 이동합니다.
                    if (pad[ny][nx] == ' ') {
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
            }
            
            // 패딩판 내부(원래 storage에 해당)에서 컨테이너 c의 4방향 중 하나라도
            // 외부와 연결된(visited가 true인) 빈 칸과 인접하면 제거합니다.
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (pad[i][j] == c) {
                        if (visited[i - 1][j] || visited[i + 1][j] || visited[i][j - 1] || visited[i][j + 1]) {
                            storage[i - 1][j - 1] = ' ';
                        }
                    }
                }
            }
        }
    }
    
    // 모든 요청 처리 후 남은 컨테이너(빈 칸이 아닌)의 개수를 셉니다.
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (storage[i][j] != ' ') answer++;
        }
    }
    
    return answer;
}
