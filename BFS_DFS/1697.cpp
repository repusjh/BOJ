#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<pair<int, int>> q;
bool visit[100001];

void findBro(int n, int cnt) {
	if (n >= 0 && n <= 100000)
		q.push({ n, cnt });
}

int main() {
	cin >> n >> k;

	q.push({ n, 0 });
	while (!q.empty()) {
		auto cur = q.front();
		int curLoc = cur.first;
		int count = cur.second;

		if (visit[curLoc]) {
			q.pop();
			continue;
		}
		visit[curLoc] = 1;

		if (curLoc == k) {
			cout << count;
			break;
		}
		q.pop();

		findBro(curLoc - 1, count + 1);
		findBro(curLoc + 1, count + 1);
		findBro(curLoc * 2, count + 1);
	}

}