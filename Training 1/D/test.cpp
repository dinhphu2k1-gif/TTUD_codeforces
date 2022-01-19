#include<iostream>

using namespace std;

unsigned long long int P = 1000000007;

unsigned long long int expmod(unsigned long long int a, unsigned long long int b){
    if (b == 1){
        return a % P;
    }
    else if (b % 2 == 0){
        long long int tmp = expmod(a % P, b / 2);
        return (tmp * tmp) % P;
    }
    else{
        long long int tmp = expmod(a % P, b / 2);
        return (((tmp * tmp) % P) * a) %P;
    }
}

int main(int argc, char const *argv[])
{
    unsigned long long int a, b;
    cin >> a >> b;
    cout << expmod(a, b);
}
