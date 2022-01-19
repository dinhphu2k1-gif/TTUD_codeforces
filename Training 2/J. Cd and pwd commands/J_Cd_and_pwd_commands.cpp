#include <bits/stdc++.h>

using namespace std;
int t;
string str, ans = "/";
vector <string> tokens;
stack <int> ind; // luu vi tri them vao trc do

void split(string &s){
    string tmp = "";
    for (int i = 3; i < s.length(); i++){
        if (s[i] != '/') tmp += s[i];
        else if (tmp != ""){
            tokens.push_back(tmp);
            tmp = "";
        } 
    }
    if (tmp != "") tokens.push_back(tmp);
}

void solve(string &s){
    if (s == "pwd"){
        cout << ans << endl;
        return;
    }

    split(s);
    if (s[3] == '/') ans = "/";
    
    int pos;
    for (int i = 0; i < tokens.size(); i++){
        if (tokens[i] != ".."){
            ind.push(ans.length());
            ans += tokens[i] + '/';
            // cout << ind.top() << " ";
        }
        else if (!ind.empty()) {
            pos = ind.top();
            ind.pop();
            // cout << pos << " " << ans.length() << endl;
            ans.erase(ans.begin() + pos, ans.end());
        }
    }

    // cout << "ok" << endl;
    tokens.clear();
}

int main(){
    // freopen("input.txt", "r", stdin);
    cin >> t;
    getchar();
    while (t--){
        getline(cin, str);
        solve(str);
    }

    // for (int i = 0; i < tokens.size(); i++){
    //     cout << tokens[i] << endl;
    // }
    // fclose(stdin);
    return 0;
}