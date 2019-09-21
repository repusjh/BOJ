#include <bits/stdc++.h>
using namespace std;

int n, m, popValue, popIndexNow, cnt;
deque<int> deq;

void moveL();
void moveR();

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		deq.push_back(i);

	for (int i = 0; i < m; i++) {
		cin >> popValue;
		for (int j = 0; j < deq.size(); j++) {
			if (deq[j] == popValue) {
				popIndexNow = j;
				break;
			}
		}

		int left = popIndexNow;
		int right = deq.size() - popIndexNow;

		if (left > right) {
			while (deq.front() != popValue)
				moveR();
		}
		else {
			while (deq.front() != popValue)
				moveL();
		}
		deq.pop_front();
	}

	cout << cnt;
}

inline void moveL() {
	int temp = deq.front();
	deq.pop_front();
	deq.push_back(temp);

	cnt++;
}

inline void moveR() {
	int temp = deq.back();
	deq.pop_back();
	deq.push_front(temp);

	cnt++;
}