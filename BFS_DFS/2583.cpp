#include <bits/stdc++.h>
using namespace std;

int m, n, k, cnt;
int ldx, ldy, rux, ruy;
int paper[101][101];
int visit[101][101];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

queue<pair<int, int>> q;
vector<int> sizes;

int main() {
	ios::sync_with_stdio(0);

	cin >> m >> n >> k;

	//uncompleted
	for (int i = 0; i < k; i++) {
		cin >> ldx >> ldy >> rux >> ruy;
		for (int j = ldx; j < rux; j++) {
			for (int k = ldy; k < ruy; k++) {
				paper[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//paper가 0이면 탐색 시작
			if (visit[i][j] || paper[i][j]) continue;
			cnt++;
			int tempSize = 0;

			visit[i][j] = 1;
			q.push({ i, j });
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				tempSize++;
				for (int k = 0; k < 4; k++) {
					int curX = cur.first + dx[k];
					int curY = cur.second + dy[k];

					if (curX < 0 || curX >= n || curY < 0 || curY >= m) continue;
					if (visit[curX][curY] || paper[curX][curY]) continue;

					visit[curX][curY] = 1;
					q.push({ curX, curY });
				}
			}
			sizes.push_back(tempSize);
		}
	}
	cout << cnt << '\n';
	sort(sizes.begin(), sizes.end());
	for (auto a : sizes) cout << a << ' ';
}