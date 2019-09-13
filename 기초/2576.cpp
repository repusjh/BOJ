#include <bits/stdc++.h>
using namespace std;
#define MAX_INDEX 7

int main(){
    int nums[MAX_INDEX], sum = 0;
    for (int i = 0; i < MAX_INDEX; i++){
        cin >> nums[i];
        if (nums[i] % 2 != 0)
            sum += nums[i];
    }

    int min  = 101;
    for (int i = 0; i < MAX_INDEX; i++){
        if (min > nums[i] && (nums[i] % 2 != 0))
            min = nums[i];
    }

    if (min == 101)
        cout << -1;
    else{
        cout << sum << '\n';
        cout << min;
    }
        
    return 0;
}