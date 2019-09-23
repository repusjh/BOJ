#include <bits/stdc++.h>
using namespace std;

string str;
stack<char> st;
int iron = 0;

int main(){
    cin >> str;

    for (int i = str.length() - 1; i >= 0; i--){
        if (str[i] == ')'){
            if (str[i - 1] == '('){
                iron += st.size();
                i--;
            }
            else
                st.push(1);
        }
        else{
            iron++;
            st.pop();
        }
    }

    cout << iron << '\n';
}