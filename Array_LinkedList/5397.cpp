#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

int L;

vector<char> result;

int main(){
	cin >> L;
	for (int i = 0; i < L; i++){
		list<char> li;
		list<char>::iterator it;
		string input;

		cin >> input;
		it = li.begin();
		for (auto a : input){
			if (a == '<'){
				if(it != li.begin() && !li.empty())
					it--;
			}
			else if (a == '>'){
				if(it != li.end() && !li.empty())
					it++;
			}
			else if (a == '-'){
				if(it != li.begin() && !li.empty()){
					it--;
					it = li.erase(it);
				}
			}
			else {
				li.insert(it, a);
			}
		}

		for (auto a : li)
			result.push_back(a);
		result.push_back('\n');
	}
	for (auto a : result)
		cout << a;

}