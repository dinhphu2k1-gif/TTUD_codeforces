#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> arr, subarr;

void input(){
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
}

int check(){
    int index = n;
    int tmp = arr[index - 1];
    subarr.push_back(tmp);
    for (int i = index - 2; i >= 0; i--){
        if (arr[i] < tmp){
            subarr.push_back(arr[i]);
            index = i;
            break;
        }
        subarr.push_back(arr[i]);
        tmp = arr[i];
    }
    if (subarr.size() == n) return -1;
    return index;
}

void output(){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

void solve(){
    int index = check();
    // cout << (index== n) << endl;
    // TH1:day dat den cuc han nhu 5 4 3 2 1, khong ton tai hoan vi phia sau
    if (index == -1){
        cout << -1;
        return ;
    } 
    
    //TH2 : day chua dat den cuc han nhu 3 2 1 4 5 -> dao 2 so cuoi thanh 3 2 1 5 4
    // if (index == n){
    //     int tmp = arr[n - 1];
    //     arr[n - 1] = arr[n - 2];
    //     arr[n - 2] = tmp;
    //     output();
    //     return;
    // }

    // TH3: day dat den cuc han tai 1 diem nao do
    int numFlag = arr[index];
    sort(subarr.begin(), subarr.end());
    
    for (int i : subarr){
        if (i > numFlag){
            numFlag = i;
            break;
        }
    }

    arr[index] = numFlag;
    int i = index + 1, j = 0;
    while (i < n){
        if (subarr[j] == numFlag){
            j++; 
        }
        else {
            arr[i] = subarr[j];
            i++;
            j++;
        }
    }
    output();
}

int main(){
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);

    solve();

    return 0;
}