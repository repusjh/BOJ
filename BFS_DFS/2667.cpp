#include <bits/stdc++.h>
using namespace std;

int n, danji;
string line[26];
bool visit[26][26];
queue<pair<int, int>> q;
vector<int> gagus;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
			cin >> line[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (line[i][j] == '0' || visit[i][j]) continue;
			int gagu = 0;

			visit[i][j] = 1;
			gagu++;
			q.push({ i, j });
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = cur.first + dx[k];
					int ny = cur.second + dy[k];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visit[nx][ny] || line[nx][ny] == '0') continue;

					visit[nx][ny] = 1;
					q.push({ nx, ny });
					gagu++;
				}
			}
			gagus.push_back(gagu);
			danji++;
		}
	}

	cout << danji << '\n';
	sort(gagus.begin(), gagus.end());
	for (auto a : gagus) cout << a << '\n';
}