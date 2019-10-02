#include <bits/stdc++.h>
using namespace std;

struct tomato{
    int row, col;
};

int board[1001][1001];
int n, m;
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

queue<tomato> q;

int main(){
    cin >> m >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            if (board[i][j] == 1)
                q.push({i, j});
        }
    }

    while (!q.empty()){
        auto cur = q.front();
        q.pop();
        for (int k = 0; k < 4; k++){
            int nr = cur.row + dr[k];
            int nc = cur.col + dc[k];
            if (nr < 0 || nr >= n || nc < 0 || nc >=m) continue;
            if (board[nr][nc]) continue; //0이여야 방문함. 양수면 이미 방문한것, 음수면 벽

            //토마토가 있는곳의 좌표를 모두 큐에 넣어뒀기 때문에 동시에 탐색 시작함.
            //즉, 어떤 지점으로부터 가까히 있는 토마토가 그 지점을 먼저 방문하므로 멀리있는 토마토는 그 지점을 방문하지 않음.
            board[nr][nc] = board[cur.row][cur.col] + 1;
            
            q.push({nr, nc});
        }
    }

    int ans = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!board[i][j]){
                cout << -1;
                return 0;
            }
            if (ans < board[i][j])
                ans = board[i][j];
        }
    }

    cout << ans - 1;

}