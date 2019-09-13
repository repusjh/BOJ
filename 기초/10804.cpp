#include <bits/stdc++.h>
using namespace std;

int cards[20];

void changOrder(int a, int b){
    int temp;
    while(a < b){
        swap(cards[a - 1], cards[b - 1]);
        a += 1;
        b -= 1;
    }
}

int main(){
    int a, b;

    for (int i = 0; i < 20; i++){
        cards[i] = i + 1;
    }

    for (int i = 0; i < 10; i++){
        cin >> a >> b;
        changOrder(a, b);
    }

    for (auto a : cards)
        cout << a << ' ';
}