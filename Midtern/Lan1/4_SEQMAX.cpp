#include <bits/stdc++.h>

using namespace std;

int n, k;
vector <double> a, b;
double res = -DBL_MAX;
double sum = 0;
double L = DBL_MAX, R = -DBL_MAX;

void input(){
    cin >> n >> k;
    double tmp;
    b.resize(n+1);
    a.push_back(0);
    for (int i = 1; i <= n; i++){
        cin >> tmp;
        L = min(L, tmp);
        R = max(R, tmp);
        sum += tmp;
        a.push_back(sum);
    }
}

double solve(double left, double right){
    
    if (right - left < 1e-7) return res;

    double mid = (right + left) / 2;
    // cout << left << " " << mid << " " << right << endl;
    for (int i = 1; i <= n; i++){
        b[i] = a[i] - mid * i;
    }
    // for (int i = 1; i <= n; i++){
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    int mark = 0;
    double mini = 0;
    for (int i = k ; i <= n; i++){
        mini = min(mini, b[i-k]);
        if (b[i] >= mini){
            res = max(res, mid);
            mark = 1;
            break;
        }
        
    }
    if (mark == 0){
        return solve(left, mid);
    }
    else {
        return solve(mid, right);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);
    // cout << sum << endl;
    if (L != R) printf("%.5lf", solve(L, R));
    else printf("%.5lf", solve(-sum, sum));
    
    return 0;
}