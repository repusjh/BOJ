#include <bits/stdc++.h>
using namespace std;

int n, temp, j = 1;
stack<int> st;
vector<char> PushPop;

int main(){
    cin >> n;
    st.push(0);

    for(int i = 0; i < n; i++){
        cin >> temp;
        if (st.top() < temp) {
            while(st.size() <= temp){
                PushPop.push_back('+');
                st.push(j++);
            }
        }
        if (st.top() == temp){
            PushPop.push_back('-');
            st.pop();
        }
        if (st.top())
    }
}