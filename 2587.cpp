#include <bits/stdc++.h>
using namespace std;

#define ARRAY_SIZE 5

int main(){
    int nums[ARRAY_SIZE], sum = 0;

    for (int i = 0; i < ARRAY_SIZE; i++){
        cin >> nums[i];
        sum += nums[i];
    }

    sort(nums, nums + ARRAY_SIZE);

    cout << sum / ARRAY_SIZE << '\n';
    cout << nums[2];
}