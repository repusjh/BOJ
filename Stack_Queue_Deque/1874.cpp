#include <bits/stdc++.h>
using namespace std;

int n, j = 1, errorFlag = 0, recurCount = 0;
stack<int> st;
vector<char> PushPop;

bool isInStack(int);

int main() {
	cin >> n;
	st.push(0);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num > st.top()) {
			for (; j <= num; j++) {
				st.push(j);
				PushPop.push_back('+');
			}
		}

		if (recurCount != 0 && !isInStack(num)) {
			errorFlag = 1;
			break;
		}
		recurCount++;

		if (num < st.top()) {
			if (!isInStack(num)) {
				errorFlag = 1;
				break;
			}
			else {
				while (st.top() != num) {
					st.pop();
					PushPop.push_back('-');
				}
			}
		}

		st.pop();
		PushPop.push_back('-');
	}

	if (errorFlag)
		cout << "NO";
	else
		for (auto a : PushPop)
			cout << a << '\n';
}

bool isInStack(int n) {
	stack<int> tempStack = st;
	while (!tempStack.empty()) {
		if (tempStack.top() == n)
			return true;
		tempStack.pop();
	}
	return false;
}