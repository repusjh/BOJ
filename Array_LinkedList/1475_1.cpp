#include <bits/stdc++.h>
using namespace std;

string room;
int nums[10];

int main(){
    cin >> room;
    for (auto a : room)
        nums[a - '0']++;
    
    nums[6] = nums[9]= ((nums[6] + nums[9] + 1) / 2);
    
    int max = nums[0];
    for (auto a : nums){
        if(a > max)
            max = a;
    }
    cout << max;
}