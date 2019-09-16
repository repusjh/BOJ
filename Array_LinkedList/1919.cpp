#include <iostream>
#include <string>

using namespace std;

int inStr1[26];
int inStr2[26];
string str1;
string str2;
int sum;

int main(){
	cin >> str1;
	cin >> str2;

	for (auto a : str1)
		inStr1[a - 'a']++;
	for (auto a : str2)
		inStr2[a - 'a']++;

	for (int i = 0; i < 26; i++)
		sum += max(inStr1[i], inStr2[i]) - min(inStr1[i], inStr2[i]);
	
	cout << sum;
}