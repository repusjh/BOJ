#include <bits/stdc++.h>
using namespace std;

int cnt;
int n, r, c;

void z(int srow, int scol, int drow, int dcol){
    if (!(srow <= r && r <= drow && scol <= c && c <= dcol)){
        cnt += (drow - srow + 1) * (dcol - scol + 1);
        return;
    }
    else{
        if (srow == drow && scol == dcol){
            cnt++;
            if (srow == r && scol == c){
                cout << cnt - 1;
                exit(0);
            }
            return;
        }
    }

    z(srow, scol, (srow + drow)/2, (scol + dcol)/2);
    z(srow, (scol + dcol)/2 + 1, (srow + drow)/2, dcol);
    z((srow + drow)/2 + 1, scol, drow, (scol + dcol)/2);
    z((srow + drow)/2 + 1, (scol + dcol)/2 + 1, drow, dcol);
}

int main(){
    cin >> n >> r >> c;
    int powerOfTwo = pow(2, n);
    z(0, 0, powerOfTwo - 1, powerOfTwo - 1);
}