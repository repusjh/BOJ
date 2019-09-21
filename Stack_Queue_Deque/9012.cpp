#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int numOfOpen = 0, flag = 0;
		cin >> str;

		for (int j = 0; str[j]; j++) {
			if (str[j] == '(')
				numOfOpen++;
			else
				numOfOpen--;
			if (numOfOpen < 0)
				flag = 1;
		}
		(flag || !(numOfOpen == 0)) ? cout << "NO\n" : cout << "YES\n";
	}
}