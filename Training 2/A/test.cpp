#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base :: sync_with_stdio (0);
    cin.tie (0); cout.tie (0);
    // freopen("input.txt", "r", stdin);
    long long n;
    long long tmp;
    vector <long long> heights;
    vector <long long> L, R;
    while (1) {
        cin >> n;
        if (n == 0) break;
        for (long long i = 0; i < n; i++){
            cin >> tmp;
            heights.push_back(tmp);
        }

        // tim can trai cua heights[i]
        for (long long i = 0; i < n; i++){
            long long index = i - 1; 
            while (index >= 0){
                if (heights[index] >= heights[i]){
                    index--;
                }
                else break;
            }
            L.push_back(index + 1);
        } 

        // tim can phai cua heights[i]
        for (long long i = 0; i < n; i++){
            long long index = i; 
            while (index < n){
                if (heights[index] >= heights[i]){
                    index++;
                }
                else break;
            }
            R.push_back(index - 1);
        } 

        //max area = heights[i] * (khoang cach 2 can trai va phai)
        long long res = 0;
        for(long long i = 0; i < n; i++){
            res = max(res, heights[i] * (R[i] - L[i] + 1));
        }
        cout << res << endl;

        //xoa cac mang
        heights.clear();
        L.clear();
        R.clear();
    }
    // fclose(stdin);

    return 0;
}