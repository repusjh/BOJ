#include <bits/stdc++.h>
using namespace std;

int n;
string line[101];
bool visit[101][101];
int non;
int blind;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

queue<pair<int, int>> q;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> line[i];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (visit[i][j]) continue;
            char looking = line[i][j];

            non++; 
            visit[i][j] = 1;
            q.push({i, j});
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                for (int k = 0; k < 4; k++){
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visit[nx][ny] || line[nx][ny] != looking) continue;

                    visit[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    fill(visit[0], visit[0] + sizeof(visit)/sizeof(bool) + 1, 0);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (visit[i][j]) continue;
            char looking = line[i][j];

            blind++; 
            visit[i][j] = 1;
            q.push({i, j});
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                for (int k = 0; k < 4; k++){
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (visit[nx][ny]) continue;

                    if (looking == 'B'){
                        if (line[nx][ny] != 'B') continue;
                    }
                    else{
                        if (line[nx][ny] == 'B') continue;
                    }

                    visit[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << non << ' ' << blind;

}