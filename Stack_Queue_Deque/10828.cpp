#include <bits/stdc++.h>
using namespace std;

string command;
int st[10001], top;
int n, tempData;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> command;

        if (command == "push"){
            cin >> tempData;
            st[top++] = tempData;
        }
        else if (command == "pop"){
            if (top == 0)
                cout << -1 << '\n';
            else{
            cout << st[--top] << '\n';
            }
        }
        else if (command == "size"){
            cout << top << '\n';
        }
        else if (command == "empty"){
            if (top == 0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else {
            if (top == 0)
                cout << -1 << '\n';
            else{
                cout << st[top - 1] << '\n';
            }
        }
    }
}