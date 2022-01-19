#include <bits/stdc++.h>

using namespace std;
const int T = 1000000000;
int n = 10000;

int random(int L, int H){
	return (rand()<<16|rand()) % (H-L+1) + L;
}   

int main(){
    freopen("input.txt", "w", stdout);
    int a = 0, b;
    cout << n << endl;
    for (int i = 0; i < n; i++){
        if (i % 100 == 0) a = random(-T, T);
        cout << a << " ";
    }
    cout << endl;
    cout << n << endl;
    for (int i = 0; i < n; i++){
        a = random(1, n);
        b = random(-T, T);
        cout << a << " " << b << endl;
    }

    fclose(stdout);

    return 0;
}