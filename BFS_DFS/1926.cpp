#include <bits/stdc++.h>
using namespace std;

int n, m, maxVal, num;
int board[501][501];
bool visited[501][501];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!visited[i][j] && board[i][j]){
                num++;
                visited[i][j] = 1;
                q.push({i, j});
                int boardSize = 0;

                while(!q.empty()){
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++){
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if (visited[nx][ny] || !board[nx][ny]) continue;

                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                    boardSize++;
                }
                maxVal = max(maxVal, boardSize);
            }
        }
    }

    cout << num << '\n' << maxVal;

}