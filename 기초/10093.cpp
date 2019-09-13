#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b;
    cin >> a >> b;

    if (a > b)
        swap(a, b);
    
    if(a == b)
        printf("%d", 0);
    else{
        printf("%lld\n", b - a - 1);

        for (long long i = a + 1; i < b; i++)
            printf("%lld ", i);
    }

    
}