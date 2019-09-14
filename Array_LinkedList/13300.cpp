#include <bits/stdc++.h>
using namespace std;

int n, k, s, y, room;
int students[6][2] = {0,};

int main(){
    cin >> n >> k;
    for (int i = 0 ; i < n; i++){
        cin >> s >> y;
        students[y - 1][s]++;
    }

    for (int i = 0 ; i < 6; i++){
        for (int j = 0; j < 2; j++){ 
            if(students[i][j] % k)
                room++;
            room += (students[i][j] / k);
        }
    }

    cout << room;


}