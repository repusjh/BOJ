#include <bits/stdc++.h>
using namespace std;

int height[9], sum, flag;

int main(){
    for (int i = 0; i < 9; i++){
        cin >> height[i];
        sum+= height[i];
    }
    for (int i = 0; i < 8 && flag == 0; i++){
        for (int j = i + 1; j <9 && flag == 0; j++){
            if (sum - height[i] - height[j] == 100){
                height[i] = height[j] = 0;
                flag = 1;
            }
        }
    }

    sort(height, height + 9);
    for(int i = 2; i < 9; i++){
        cout << height[i] << '\n';
    }
}