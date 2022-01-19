#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int n;
    int tmp;
    vector <int> heights;
    stack <int> S; // luu cac can trai cua hinh chu nhat
    // luu y: S luu cac chi so khong phai gia tri

    while (1) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> tmp;
            heights.push_back(tmp);
        }

        // them linh canh
        heights.push_back(0);
        S.push(-1);

        int ans = 0;
        int h, w;

        /* neu tai i, heights < heights da ton tai trong stack
            tinh dien tich va so sanh, (loai bo cac can trai da tinh)
            sau moi lan tinh, ta se thu dc can trai moi
        */
        for (int i = 0; i <= n; i++) {
            // i la can phai cua hinh chu nhat
            while (S.size() > 1 && heights[i] < heights[S.top()]){
                // cout << S.top() << " " << i << endl;
                h = heights[S.top()]; // chieu cao cua hinh chu nhat
                S.pop();
                w = i - S.top() - 1; // chieu rong cua hinh chu nhat
                ans = max(ans, h * w);
            }
            S.push(i);
            
        }
        cout << ans << endl;

        // xoa mang
        heights.clear();
        while(!S.empty()) {
            S.pop();
        }
    }
    fclose(stdin);

    return 0;
}