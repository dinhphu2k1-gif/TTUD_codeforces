#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    string str;
    cin >> str;

    int mark = 1;
    while (mark){
        mark = 0;
        for (int i = str.length() - 2; i >= 0; i--){
            // cout << str << endl;
            if (str[i] == str[i + 1]) {
                str.erase(str.begin() + i, str.begin() + i + 2);
                mark = 1;
            }
        }
    }
    if (str.empty()) cout << "Yes";
    else cout << "No";

    fclose(stdin);
    return 0;
}