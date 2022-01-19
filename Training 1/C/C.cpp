#include <bits/stdc++.h>

using namespace std;
const unsigned long long P = 1000000000 + 7;

int main(){
    unsigned long long a, b;
    cin >> a >> b;
    cout << (a%P + b%P) % P;
    return 0;
}