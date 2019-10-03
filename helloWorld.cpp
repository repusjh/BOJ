#include <iostream>
#include <string>
using namespace std;

void test(int a){
    if (a > 0) test(a - 1);
}

int main(){
    test(35000);
    cout << "done";
}