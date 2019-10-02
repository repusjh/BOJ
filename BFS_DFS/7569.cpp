#include <bits/stdc++.h>
using namespace std;

 typedef struct{
    int h, row, col;
}tomato;

int h, n, m;
int board[101][101][101];
int dh[] = {1, -1, 0, 0, 0, 0};
int dr[] = {0, 0, 0, 1, 0, -1};
int dc[] = {0, 0, 1, 0, -1, 0};

queue<tomato> q;

int main(){
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                cin >> board[i][j][k];
                if (board[i][j][k] == 1)
                    q.push({i, j, k});
            }
        }
    }

    while (!q.empty()){
        auto cur = q.front();
        q.pop();
        for (int i = 0 ; i < 6; i++){
            int nh = cur.h + dh[i];
            int nr = cur.row + dr[i];
            int nc = cur.col + dc[i];
            if (nh < 0 || nh >= h || nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (board[nh][nr][nc]) continue;

            board[nh][nr][nc] = board[cur.h][cur.row][cur.col] + 1;
            q.push({nh, nr, nc});
        }
    }
    int ans = -1;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                if (!board[i][j][k]){
                    cout << -1;
                    return 0;
                }
                if (ans < board[i][j][k])
                    ans = board[i][j][k];
            }
        }
    }
    cout << ans - 1;
}