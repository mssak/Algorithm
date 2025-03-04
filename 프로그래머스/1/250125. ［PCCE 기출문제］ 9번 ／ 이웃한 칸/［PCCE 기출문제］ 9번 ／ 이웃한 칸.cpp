#include <bits/stdc++.h>

using namespace std;

bool chk(vector<vector<string>>& board, int y,int x){
    int ymx=board.size();
    int xmx=board[0].size();
    if(y<ymx&&x<xmx&&y>=0&&x>=0){
        return true;
    }
    return false;
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    string goal=board[h][w];
    int dy[4]={0,1,-1,0};
    int dx[4]={1, 0, 0, -1};
    
    
        for(int i=0;i<4;i++){
            int ny=h+dy[i];
            int nx=w+dx[i];
            if(chk(board,ny,nx) && board[ny][nx]==goal){
                answer++;
            }
    }
    
    return answer;
}