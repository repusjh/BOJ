#include <iostream>
#include <list>
#include <vector>

using namespace std;

int n, k;
list<int> li;
list<int>::iterator it;
vector<int> v;

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		li.push_back(i);
	}

	it = li.begin();

	while(!li.empty()){
		for (int i = 0; i < k - 1; i++){
			if(it == li.end())
				it = li.begin();
			it++;
		}
		if(it == li.end())
			it = li.begin();
		v.push_back(*it);
		it = li.erase(it);
	}

	cout << '<';
	for (int i = 0; i < v.size(); i++){
		cout << v[i];
		if (i == v.size() - 1)
			break;
		cout << ", ";
	}
	cout << '>';
}