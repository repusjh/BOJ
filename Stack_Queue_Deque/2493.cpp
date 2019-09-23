#include <stack>
#include <iostream>
#include <utility>
using namespace std;

stack<pair<int, int>> height;
int n, temp;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> temp;
		if (height.empty()){
			cout << 0 << ' ';
			height.push(make_pair(i, temp));
		}
		else{
			if (height.top().second <= temp){
				while(!height.empty() && height.top().second <= temp){
					height.pop();
				}
			}
			if(height.empty())
				cout << 0 << ' ';
			else
				cout << height.top().first << ' ';
			height.push(make_pair(i, temp));
		}	
	}
	return 0;
}