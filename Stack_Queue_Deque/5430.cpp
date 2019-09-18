#include <bits/stdc++.h>
using namespace std;

int t, n,  errorFlag = 0;
string p, li, token;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++) {
		deque<int> deq;

		cin >> p >> n >> li;

        //[] 지우기
        li.erase(0, 1);
        li.erase(li.length() - 1, 1);

        //쉼표를 기준으로 token 쪼개기, toekn을 deque에 push, li 지워가면서 반복
        while(li.length() > 0){
            token = li.substr(0, li.find(','));
            deq.push_back(atoi(token.c_str()));
            li.erase(0, token.length() + 1);
        }

		for (auto a : p) {
			if (a == 'R')
				reverse(deq.begin(), deq.end());
			else {
				if (deq.empty()) {
					errorFlag = 1;
					break;
				}
				else {
					deq.pop_front();
				}
			}
		}

		if (errorFlag) {
			cout << "error" << '\n';
		}
		else {
			cout << '[';
			for (deque<int>::iterator it = deq.begin(); !deq.empty();) {
				cout << *it;
				if (++it == deq.end())
					break;
				cout << ',';
		    }
            cout << ']' << '\n';
	    }
        errorFlag = 0;
    }
}