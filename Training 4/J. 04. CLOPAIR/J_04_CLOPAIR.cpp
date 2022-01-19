#include <bits/stdc++.h>

using namespace std;

struct point
{
    long long x, y;
    int id;
};

int n;
vector <point> A;
int pos1, pos2;
double res = DBL_MAX;

bool cmp_x(point a, point b){
    return a.x < b.x;
}

bool cmp_y(point a, point b){
    return a.y < b.y;
}

double dis(point a, point b){
    return sqrt((double)pow(b.x-a.x, 2) + (double)pow(b.y-a.y, 2));
}

void update(point a, point b){
    double d = dis(a, b);
    if (d < res){
        res = d;
        pos1 = a.id;
        pos2 = b.id;
    }
}

void input(){
    cin >> n;
    A.resize(n);

    for (int i = 0; i < n; i++){
        cin >> A[i].x >> A[i].y;
        A[i].id = i;
    }

    sort(A.begin(), A.end(), cmp_x);
}

void solve(int left, int right){
    if (left >= right ) return ;
    if (left + 1 == right){
        update(A[left], A[right]);
        return ;
    }

    int mid = (left + right) /2;
    int mid_x = A[mid].x;

    solve(left, mid);
    solve(mid + 1, right);

    vector <point> v;
    for (int i = left; i <= right; i++){
        if (abs(A[i].x - mid_x) <= res){
            v.push_back(A[i]);
        }
    }

    sort(v.begin(), v.end(), cmp_y);
    double tmp = res;
    for (int i = 0; i < v.size(); i++){
        int j = i + 1;
        while (j < v.size() && v[j].y - v[i].y < tmp){
            update(v[i], v[j]);
            j++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    input();
    // fclose(stdin);

    solve(0, n -1);
    cout << pos1 << " " << pos2 << " ";
    printf("%.6lf", res);

    return 0;
}