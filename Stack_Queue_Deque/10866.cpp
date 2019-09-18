#include <bits/stdc++.h>
using namespace std;

int deq[20003];
int front = 10000, back = 10000;
int n;
string command;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> command;

        if (command == "push_front"){
            int tempData;
            cin >> tempData;

            deq[--front] = tempData;
        }
        else if (command == "push_back"){
            int tempData;
            cin >> tempData;

            deq[back++] = tempData;
        }
        else if (command == "pop_front"){
            if (front == back)
                cout << -1 << '\n';
            else
                cout << deq[front++] << '\n';
        }
        else if (command == "pop_back"){
            if (front == back)
                cout << -1 << '\n';
            else
                cout << deq[--back] << '\n';
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
            else
                cout << deq[front] << '\n';
        }
        else{
            if (front == back)
                cout << -1 << '\n';
            else
                cout << deq[back - 1] << '\n';
        }
    }
}