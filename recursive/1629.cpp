#include <bits/stdc++.h>
using namespace std;

long long getMul(long long a, long long b, long long c){
    if (b == 0) return 1;
    long long val = getMul(a, b / 2, c);
    val = val * val % c;
    if (b % 2) return (a * val) % c;
    return (val) % c;
}

int main(){
    long long a, b, c;
    cin >> a >> b >> c;

    cout << getMul(a, b, c);
}