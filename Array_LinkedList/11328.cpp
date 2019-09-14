#include <bits/stdc++.h>
using namespace std;

int n, s1[26], s2[26];
string str1, str2;
char isPossible[1001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2;
		for (auto a : str1)
			s1[a - 'a']++;
		for (auto a : str2)
			s2[a - 'a']++;

		for (int j = 0; j < 26; j++) {
			if (s1[j] != s2[j]) {
				isPossible[i] = 'I';
				break;
			}
			isPossible[i] = 'P';
		}
		fill(s1, s1 + 26, 0);
		fill(s2, s2 + 26, 0);
	}

	for (int i = 0; i < n; i++) {
		if (isPossible[i] == 'I')
			cout << "Impossible\n";
		if (isPossible[i] == 'P')
			cout << "Possible\n";
	}
}