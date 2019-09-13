#include <bits/stdc++.h>
using namespace std;

char str[101];
int alphabet[26];

int main(){
    cin >> str;

    int i = 0;
    while (str[i] != '\0'){
        alphabet[str[i] - 'a']++;
        i++;
    }

    for (auto a : alphabet)
        cout << a << " ";

    return 0;
}