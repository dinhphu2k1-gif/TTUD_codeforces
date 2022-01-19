#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector <long long> arr;
    long long tmp;

    for(int i = 0; i < n; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }   
    // cout << "ok";

    long long res = arr[0];
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        res = max(sum, res);
        if (sum < 0){
            sum = 0;
        }
    } 
    cout << res;
    return 0;
}