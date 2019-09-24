#include <bits/stdc++.h>
using namespace std;

int n, m;
int dis[101][101];
string maze[101];
bool visited[101][101];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}

	visited[0][0] = 1;
	dis[0][0] = 1;
	q.push({ 0, 0 });
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = cur.first + dx[k];
			int ny = cur.second + dy[k];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (visited[nx][ny] || maze[nx][ny] == '0') continue;

			visited[nx][ny] = 1;
			dis[nx][ny] = dis[cur.first][cur.second] + 1;
			q.push({ nx, ny });
		}
	}
	cout << dis[n - 1][m - 1];
}