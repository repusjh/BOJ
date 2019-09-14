#include <bits/stdc++.h>
using namespace std;

list<char> editor;
list<char>::iterator cursor;
string str;
char command;
int n;

void L() {
	if (cursor != editor.begin())
		cursor--;
}

void D() {
	if (cursor != editor.end())
		cursor++;
}

void B() {
	if (cursor != editor.begin()) {
		cursor--;
		cursor = editor.erase(cursor);
	}
}

void P() {
	char ch;
	cin >> ch;
	editor.insert(cursor, ch);
}

int main() {
	cin >> str;
	for (auto a : str)
		editor.push_back(a);
	cursor = editor.end();

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> command;
		switch (command) {
		case 'L': L(); break;
		case 'D': D(); break;
		case 'B': B(); break;
		case 'P': P(); break;
		}
	}

	cursor = editor.begin();
	for (auto a : editor)
		cout << a;
}