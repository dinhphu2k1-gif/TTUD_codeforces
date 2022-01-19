#include <bits/stdc++.h>

using namespace std;
const unsigned long long P = 1000000000 + 7;

unsigned long long calculate(unsigned long long a, unsigned long long b){
    unsigned long long res = 1;
    for (unsigned long long i = 0; i < b; i++ ){
        res *= a % P;
        res %= P;
    }
    return res;
}

int main(){
    unsigned long long a, b;
    ifstream f ("input.txt");
    f >> a >> b;
    // cin >> a >> b;

    a = a % P;
    // b = b % P;

    unsigned long long res, tmp = calculate(a, b / 2);
    // cout << tmp << endl;
    if (b % 2 == 0){
        res = tmp * tmp;
    }
    else {
        res = tmp * tmp;
        res = res % P;
        res *= a;
    }
    cout << res % P;

    return 0;
}

