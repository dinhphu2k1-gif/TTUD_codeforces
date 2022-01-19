#include <bits/stdc++.h>

using namespace std;

int main(){
    int d = 1000000007;
    long long a, b;
    ifstream f ("input.txt");
    f >> a >> b;

    cout << a %d << " " << b%d << endl;
    cout << (a + b) % d << endl;

    return 0;
}