#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int W, H;
string board[101];
int visited[101][101];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void bfs(int nowr, int nowc){
    queue<tuple<int, int, int>> q;
    q.push({nowr, nowc, -1});
    visited[nowr][nowc] = 0;

    while(!q.empty()){
        int r, c, cnt;
        tie(r, c, cnt) = q.front();
        q.pop();
        cnt++;

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            while (0 <= nr && nr < H && 0 <= nc && nc < W && board[nr][nc] != '*' && cnt <= visited[nr][nc]){
                if(board[nr][nc] == 'C'){
                    cout << cnt;
                    return;
                }
                if(cnt < visited[nr][nc]){
                    visited[nr][nc] = cnt;
                    q.push({nr, nc, cnt});
                }
                nr += dr[i];
                nc += dc[i];
            }
        }
    }
}

int main(){
    cin >> W >> H;

    int r, c;
    for(int i = 0; i < H; i++){
        cin >> board[i];
        for(int j = 0; j < W; j++){
            visited[i][j] = 987654321;
            if(board[i][j] == 'C'){
                r = i;
                c = j;
            }
        }
    }

    bfs(r, c);
    return 0;
}
