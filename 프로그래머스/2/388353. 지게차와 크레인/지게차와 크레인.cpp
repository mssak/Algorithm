#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<string> storage, vector<string> requests) {
    int n = storage.size();
    int m = storage[0].size();
    
    // 4방향 이동을 위한 배열
    int dirs[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    
    // 요청을 순서대로 처리
    for (auto &req : requests) {
        char target = req[0];
        // 크레인을 사용하는 경우 (요청 문자열 길이 == 2)
        if (req.size() == 2) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (storage[i][j] == target)
                        storage[i][j] = '.';
                }
            }
        }
        // 지게차를 사용하는 경우 (요청 문자열 길이 == 1)
        else {
            // 창고 외부와 연결된 빈 칸을 찾기 위한 BFS
            vector<vector<bool>> exterior(n, vector<bool>(m, false));
            queue<pair<int, int>> q;
            // 경계에 위치한 빈 칸을 시작점으로 등록
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (storage[i][j] == '.' && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) {
                        exterior[i][j] = true;
                        q.push({i, j});
                    }
                }
            }
            // BFS를 통해 외부와 연결된 빈 칸을 전파
            while (!q.empty()) {
                auto [ci, cj] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int ni = ci + dirs[d][0];
                    int nj = cj + dirs[d][1];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    if (storage[ni][nj] != '.') continue;
                    if (!exterior[ni][nj]) {
                        exterior[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
            
            // 요청된 컨테이너 중 접근 가능한 컨테이너 제거
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (storage[i][j] == target) {
                        bool accessible = false;
                        // 경계에 위치하면 바로 접근 가능
                        if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                            accessible = true;
                        else {
                            // 인접한 4방향 중 빈 칸이 외부와 연결되어 있는지 확인
                            for (int d = 0; d < 4; d++) {
                                int ni = i + dirs[d][0];
                                int nj = j + dirs[d][1];
                                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                                if (storage[ni][nj] == '.' && exterior[ni][nj]) {
                                    accessible = true;
                                    break;
                                }
                            }
                        }
                        if (accessible)
                            storage[i][j] = '.';
                    }
                }
            }
        }
    }
    
    // 모든 요청 처리 후 남은 컨테이너 개수 계산
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (storage[i][j] != '.')
                answer++;
        }
    }
    
    return answer;
}
