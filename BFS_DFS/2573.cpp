#include <bits/stdc++.h>
using namespace std;

int n, m, year, Crashed;
int board[301][301];
bool visit[301][301];
int melt[301][301];
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
queue<pair<int, int>> q;

bool isAllZero() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j])
				return false;
		}
	}
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	while (!isAllZero()) {
		//녹는 정도 구하기
		fill(&melt[0][0], &melt[0][0] + sizeof(melt) / sizeof(int), 0);
		fill(&visit[0][0], &visit[0][0] + sizeof(visit) / sizeof(bool), 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!board[i][j]) continue;

				int neighbor = 0;
				for (int k = 0; k < 4; k++) {
					int nr = i + dr[k];
					int nc = i + dc[k];
					if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
					if (!board[nr][nc])
						neighbor++;
				}
				melt[i][j] = neighbor;
			}
		}

		//분리되어있는지 BFS
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!board[i][j] || visit[i][j]) continue;

				visit[i][j] = 1;
				q.push({ i, j });

				cnt++;
				if (cnt > 1) {
					cout << year;
					return 0;
				}

				while (!q.empty()) {
					auto cur = q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nr = cur.first + dr[k];
						int nc = cur.second + dc[k];

						if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
						if (visit[nr][nc] || !board[nr][nc]) continue;

						visit[nr][nc] = 1;
						q.push({ nr, nc });
					}
				}
			}
		}

		//melt
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!board[i][j]) continue;

				(board[i][j] - melt[i][j] <= 0) ? board[i][j] = 0 : board[i][j] = board[i][j] - melt[i][j];
			}
		}

		year++;
	}
	cout << 0;
}