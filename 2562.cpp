#include <bits/stdc++.h>
using namespace std;

int main(){
    int nums[9];

    for (int i = 0; i < 9; i++){
        cin >> nums[i];
    }

    int maxIndex = 0;
    for (int i = 0; i < 9; i++){
        if (nums[maxIndex] < nums[i])
            maxIndex = i;
    }

    cout << nums[maxIndex] << '\n';
    cout << maxIndex + 1;
}