#include <bits/stdc++.h>
using namespace std;

int main(){
    int dice[3];
    int result[6] = {0,};

    for (int i = 0; i < 3; i++){
        cin >> dice[i];
        result[dice[i] - 1]++;
    }

    sort(dice, dice + 3);

    int maxIndex = 0;
    for (int i = 0; i < 6; i++){
        if (result[maxIndex] < result[i])
            maxIndex = i;
    }

    switch(result[maxIndex]){
        case 1:
            cout << dice[2] * 100;
            break;
        case 2:
            cout << 1000 + (maxIndex + 1) * 100;
            break;
        case 3:
            cout << 10000 + (maxIndex + 1) * 1000;
            break;
    }
}