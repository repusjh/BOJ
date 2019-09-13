#include<bits/stdc++.h>
using namespace std;

int main(){
    int line[4];
    char result[3];

    for (int i = 0; i< 3; i++){
        int cnt = 0;
        for (int j = 0; j < 4; j++){
            cin >> line[j];
            if (line[j] == 0)
                cnt++;
        }
        if (cnt == 0)
            result[i] = 'E';
        else
            result[i] = 'A' + cnt - 1;
    }

    for (auto a : result)
        cout << a << '\n';
}