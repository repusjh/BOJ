#include <bits/stdc++.h>
using namespace std;

int nums[10], n, needed, six_nine;

int main() {
    cin >> n;
    if (n == 0) 
        cout << 1;
    else {
        while (n > 0) {
            nums[n % 10]++;
            n /= 10;
        }

        int max = nums[0];
        nums[6] = nums[9] = ((nums[6] + nums[9] + 1) / 2);
        for (int i = 0; i < 10; i++) {
            if (max < nums[i])
                max = nums[i];
        }
        cout << max;
    }
}