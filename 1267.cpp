#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, data, y = 0, m = 0;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> data;
        y += (((data / 30) + 1) * 10);
        m += (((data / 60) + 1) * 15);
    }

    if (y > m)
        cout << "M " << m;
    else if (y == m)
        cout << "Y M " << m;
    else
        cout << "Y " << y;
    

}