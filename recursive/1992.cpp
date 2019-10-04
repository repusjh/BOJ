#include <bits/stdc++.h>
using namespace std;

int n;
char field[65][65];

void quad(int srow, int scol, int drow, int dcol){
     //basecase
    if (srow == drow || scol == dcol){
        cout << field[srow][scol];
        return;
    }

    bool flag = false;
    char ch = field[srow][scol];
    //영역안에 서로 다른 숫자가 있다면
    for (int i = srow; i <= drow; i++){
        for (int j = scol; j <= dcol; j++){
            if (field[i][j] != ch)
                flag = true; 
        }
    }

    if (flag){
        cout << '(';
        quad(srow, scol, (srow + drow)/2, (scol + dcol)/2);
        quad(srow, (scol + dcol)/2 + 1, (srow + drow)/2, dcol);
        quad((srow + drow)/2 + 1, scol, drow, (scol + dcol)/2);
        quad((srow + drow)/2 + 1, (scol + dcol)/2 + 1, drow, dcol);
        cout << ')';
    }
    else
        cout << field[srow][scol];
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> field[i][j];
        }
        //getchar();
    }
    quad(1, 1, n, n);
}