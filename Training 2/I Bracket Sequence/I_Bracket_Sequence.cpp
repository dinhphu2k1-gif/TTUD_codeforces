#include <bits/stdc++.h>

using namespace std;
string str;
int max_count = 0;
string res;

void check(int start, int end) {
    // cout << start << " " << end << endl;
    int count = 0;
    string substr = "";
    for (int i = start + 1; i < end; i++) {
        substr += str[i];
        if (str[i] == '[') count++;
    }

    if (count > max_count){
        max_count = count;
        res = substr;
    }
}


int main(){
    // freopen("input.txt", "r", stdin);   
    cin >> str;
    // fclose(stdin);

    stack <pair <char, int>> S;
    S.push({')', -1});
    pair <char, int> c;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '(' || str[i] == '[') S.push({str[i], i});
        else {
            c = S.top();
            if ((str[i] == ']' && c.first == '[') || (str[i] == ')' && c.first == '(')) S.pop();
            else S.push({str[i], i});
        }
    }
    
    string substr;
    int start, end = str.length();
    while (!S.empty()){
        c = S.top();
        S.pop();
        start = c.second;
        check(start, end);
        end = start;
    }
    cout << max_count << endl << res;
    return 0;
}