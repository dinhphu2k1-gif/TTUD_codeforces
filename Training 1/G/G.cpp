#include <bits/stdc++.h>

using namespace std;

int main(){
    // freopen("input.txt","r",stdin);

    map <char, int> arr;
    arr['a'] = 1, arr['b'] = 2, arr['c'] = 3;
    arr['d'] = 1, arr['e'] = 2, arr['f'] = 3;
    arr['g'] = 1, arr['h'] = 2, arr['i'] = 3;
    arr['j'] = 1, arr['k'] = 2, arr['l'] = 3;
    arr['m'] = 1, arr['n'] = 2, arr['o'] = 3;
    arr['p'] = 1, arr['q'] = 2, arr['r'] = 3, arr['s'] = 4;
    arr['t'] = 1, arr['u'] = 2, arr['v'] = 3;   
    arr['w'] = 1, arr['x'] = 2, arr['y'] = 3, arr['z'] = 4;
    arr[' '] = 1;

    // cout << arr['a'];
    int t;
    string s;
    cin >> t;
    getchar();

    for (int i = 1; i <= t; i++) {
        int res = 0;
        getline(cin, s);
        for (char c : s){
            res += arr[c];
        }
        cout << "Case #" << i << ": " << res << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    return 0;
}