#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector <int> arr;

void input(){
    cin >> n >> m >> k;
    // gan gia tri dau tien cua hoan vi 1 2 3 4
    for (int i = 1; i <= m; i++) {
        arr.push_back(i);
    }
}

void output(){
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }
}     

void solve(){
    k--;
    while (k > 0){
        int foo = m - 1;
        // neu diem cuoi chua dat cuc han co the tang len 1
        // VD 1 2 3 4 -> 1 2 3 5
        // cout << (arr[foo] != n) << " ";
        if (arr[foo] != n){
            arr[foo]++;
        }
        else {
            while(arr[foo] - arr[foo-1] == 1) foo--;
            //TH hoan vi dat cuc han , VD 3 4 5 6, khong ton tai hoan vi phia sau
            foo--;
            if (foo < 0){
                cout << -1;
                return ;
            }
            else {
                arr[foo]++;
                for (int i = foo+1; i < m; i++){
                    arr[i] = arr[i-1] + 1;
                }
                
            }
        }
        k--;
        output();
        cout << endl;
    }

    // output();
}



int main(){
    freopen("input.txt", "r", stdin);
    input();
    fclose(stdin);
    solve();

    return 0;
}