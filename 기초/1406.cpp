//#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

string s;
int n;

typedef struct node {
public:
	char data;
	struct node *next;
	struct node *before;
}node;

node *insertBack(node *cur, char ch);
node *removeNode(node *cur);
node *L(node *cur);
node *D(node *cur);


int main() {
	cin >> s;
	cin >> n;
	node *cur = NULL;

	for (auto a : s) {
		cur = insertBack(cur, a);
	}

	char clicked;
	for (int i = 0; i < n; i++) {
		cin >> clicked;
		switch (clicked) {
		case 'L':
			cur = L(cur);
			break;
		case 'D':
			cur = D(cur);
			break;
		case 'B':
			cur = removeNode(cur);
			break;
		default:
			char toAppend;
			cin >> toAppend;
			cur = insertBack(cur, toAppend);
		}
	}

	//cur를 처음으로
	while (cur->before != NULL)
		cur = cur->before;

	while (cur != NULL) {
		cout << cur->data;
		cur = cur->next;
	}

}

node *insertBack(node *cur, char ch) {
	node *newNode = new node();
	newNode->data = ch;

	if (cur == NULL) {
		newNode->next = NULL;
		newNode->before = NULL;
		cur = newNode;

		return cur;
	}
	newNode->before = cur;
	newNode->next = cur->next;
	newNode->before->next = newNode;
	cur = newNode;

	return cur;
}

node *removeNode(node *cur) {
	if (cur->before == NULL) {
		delete cur;
		return NULL;
	}
	if (cur->next == NULL) {
		cur = cur->before;
		delete cur->next;
		cur->next = NULL;

		return cur;
	}

	cur->before->next = cur->next;
	cur->next->before = cur->before;

	delete cur;
	cur = cur->before;

	return cur;
}

node *L(node *cur) {
	if (cur->before == NULL)
		return cur;
	cur = cur->before;
	return cur;
}

node *D(node *cur) {
	if (cur->next == NULL)
		return cur;
	cur = cur->next;
	return cur;
}