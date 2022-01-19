#include <bits/stdc++.h>

using namespace std;

int t;
stack <char> S;
string str;

int solve(){
    cin >> str;
    for (char c : str){
        if (c == '{' || c == '[' || c == '('){
            S.push(c);
        }
        else if (c == '}'){
            if (S.top() != '{') return 0;
            S.pop();
        }
        else if (c == ']'){
            if (S.top() != '[') return 0;
            S.pop();
        }
        else {
            if (S.top() != '(') return 0;
            S.pop();
        }
    }
    return 1;
}

int main(){ 
    cin >> t;

    while(t--){
        cout << solve() << endl;
        while (!S.empty()) S.pop();
    }

    return 0;
}