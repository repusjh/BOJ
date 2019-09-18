#include <bits/stdc++.h>
using namespace std;

deque<int> deq;
deque<int>::iterator it;
int n, tempData;
string command;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> command;

        if (command == "push_front"){
            int tempData;
            cin >> tempData;

            deq.push_front(tempData);
        }
        else if (command == "push_back"){
            int tempData;
            cin >> tempData;

            deq.push_back(tempData);
        }
        else if (command == "pop_front"){
            if (deq.empty())
                cout << -1 << '\n';
            else{
                cout << deq.front() << '\n';
                deq.pop_front();
            }
        }
        else if (command == "pop_back"){
            if (deq.empty())
                cout << -1 << '\n';
            else{
                cout << deq.back() << '\n';
                deq.pop_back();
            }
        }
        else if (command == "size")
            cout << deq.size() << '\n';
        else if (command == "empty"){
            if (deq.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (command == "front"){
            if (deq.empty())
                cout << -1 << '\n';
            else
                cout << deq.front() << '\n';
        }
        else{
            if (deq.empty())
                cout << -1 << '\n';
            else
                cout << deq.back() << '\n';
        }
    }
}