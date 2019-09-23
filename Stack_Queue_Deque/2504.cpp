#include <bits/stdc++.h>
using namespace std;

string input;
int total, sub;
stack<char> st;

int main() {
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		switch (input[i]) {
		case '(':
			//out of bound
			if (input[i + 1] == ')') {
				st.push(2);
				i++;
			}
			else
				st.push('(');
			break;
		case ')':
			if (st.top() != '(') {
				cout << 0;
				return 0;
			}
			while (0 <= st.top() && st.top() <= 9) {
				sub += st.top();
				st.pop();
			}
			st.pop();
			st.push(sub * 2);
			break;
		case '[':
			//out of bound
			if (input[i + 1] == ']') {
				st.push(3);
				i++;
			}
			else
				st.push('[');
			break;
		default:
			if (st.top() != '[') {
				cout << 0;
				return 0;
			}
			while (0 <= st.top() && st.top() <= 9) {
				sub += st.top();
				st.pop();
			}
			st.pop();
			st.push(sub * 3);
			break;
		}
		sub = 0;
	}

	//肋给等 版快 盒扁贸府
	cout << (int)st.top();

}