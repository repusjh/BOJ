#include <bits/stdc++.h>
using namespace std;

int nums[101], n, v, cnt;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cin >> v;

    for (int i = 0; i < n; i++)
        if (nums[i] == v)
            cnt++;

    cout << cnt;
}