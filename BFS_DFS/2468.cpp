#include <bits/stdc++.h>
using namespace std;

int n, maxheight = -1, maxsfty = -1;
int field[101][101];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, -1, 0};

queue<pair<int, int>> q;
int max = -1;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> field[i][j];
            if (maxheight < field[i][j]) maxheight = field[i][j];
        }
    }

    for (int height = 0; height < maxheight; height++){
        bool visit[101][101] = {0,};
        int sfty = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0 ; j < n; j++){
                if (visit[i][j] || field[i][j] <= height) continue;
                sfty++;
                visit[i][j] = 1;
                q.push({i, j});
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++){
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if (nx < 0 || nx >= n|| ny < 0 || ny >= n) continue;
                        if (visit[nx][ny] || field[nx][ny] <= height) continue;

                        visit[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        if (maxsfty < sfty) maxsfty = sfty;
    }
    cout << maxsfty;
    
}