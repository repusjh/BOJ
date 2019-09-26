#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int t, m, n, k;
int worm;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<pair<int, int>> q;

int main(){
	cin >> t;
	for (int i = 0; i < t; i++){
		int field[51][51] = {0,};
		bool visit[51][51] = {0,};

		cin >> m >> n >> k;
		for (int j = 0; j < k; j++){
			int tempX, tempY;
			cin >> tempX >> tempY;
			field[tempX][tempY] = 1;
		}

		for (int j = 0; j < m; j++){
			for (int k = 0; k < n; k++){
				if (field[j][k] == 0 || visit[j][k]) continue;

				visit[j][k] = 1;
				q.push(make_pair(j, k));

				while (!q.empty()){
					pair<int, int> cur = q.front();
					q.pop();

					for (int l = 0; l < 4; l++){
						int xpos = cur.first + dx[l];
						int ypos = cur.second + dy[l];

						if (field[xpos][ypos] == 0 || visit[xpos][ypos]) continue;
						if (xpos < 0 || xpos >= m || ypos < 0 || ypos >= n) continue;

						visit[xpos][ypos] = 1;
						q.push(make_pair(xpos, ypos));
					}
				}
				worm++;
			}
		}
		cout << worm << '\n';
		worm = 0;
	}

}