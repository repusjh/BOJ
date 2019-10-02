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
            if (board[nr][nc]) continue; //0�̿��� �湮��. ����� �̹� �湮�Ѱ�, ������ ��

            //�丶�䰡 �ִ°��� ��ǥ�� ��� ť�� �־�ױ� ������ ���ÿ� Ž�� ������.
            //��, � �������κ��� ������ �ִ� �丶�䰡 �� ������ ���� �湮�ϹǷ� �ָ��ִ� �丶��� �� ������ �湮���� ����.
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