#include <bits/stdc++.h>
using namespace std;

int n, cnt;
vector<pair<int, int>> v;

void hanoi(int a, int b, int n){
    cnt++;
    int c = 6 - a - b;
    if (n == 1) v.push_back({a, b});
    else{
        hanoi(a, c, n - 1);
        v.push_back({a, b});
        hanoi(c, b, n - 1);
    }
}

int main(){
    cin >> n;
    hanoi(1, 3, n);
    cout << cnt << '\n';
    for (auto a : v){
        cout << a.first << ' ' << a.second << '\n';
    }
}