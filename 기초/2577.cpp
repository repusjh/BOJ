#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, mulResult;
    int count[10] = {0,};
    cin >> a >> b >> c;
    mulResult = a * b * c;

    while(mulResult != 0){
        count[mulResult % 10]++;
        mulResult /= 10;
    }

    for (auto a : count)
        cout << a << '\n';
}