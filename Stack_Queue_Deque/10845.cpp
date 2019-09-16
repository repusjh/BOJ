#include <bits/stdc++.h>
using namespace std;

int qu[10001], front, back;
string command;
int n, tempData;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> command;

        if (command == "push"){
            cin >> tempData;
            qu[back++] = tempData;
        }
        else if (command == "pop"){
            if (front == back)
                cout << -1 << '\n';
            else
                cout << qu[front++] << '\n';
        }
        else if (command == "size")
            cout << back - front << '\n';
        else if (command == "empty"){
            if (front == back)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (command == "front"){
            if (front == back)
                cout << -1 << '\n';
            else{
                cout << qu[front] << '\n';
            }
        }
        else{
            if (front == back)
                cout << -1 << '\n';
            else{
                cout << qu[back - 1] << '\n';
            }
        }
    }
}