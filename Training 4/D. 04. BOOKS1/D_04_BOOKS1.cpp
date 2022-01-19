#include <bits/stdc++.h>
#define ll long long
const int inf = 0x7fffffff;
using namespace std;
int n, k;
vector <int> arr;

void print(ll mark)
{
    ll sum = 0;
    vector<int> v;
    int cnt = 1;
    for (int i = n - 1; i > -1; i--)
    {
        if (sum + arr[i] > mark || i == k - cnt - 1)
        {
            sum = 0;
            v.push_back(-1);
            cnt++;
        }
        sum += arr[i];
        v.push_back(arr[i]);
    }
    reverse(v.begin(), v.end());
    int l = v.size();
    for (int i = 0; i < l; i++)
    {
        if (v[i] == -1) cout << "/ ";
        else
            cout << v[i] << " ";
    }
    cout << endl;
}
bool check(ll mid)
{
    int cnt = 1;
    ll sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        if (sum + arr[i] > mid)
        {
            cnt++;
            sum = 0;
        }
        sum += arr[i];
    }
    //cout << cnt << endl;
    return (cnt <= k);
}
void binary(ll low, ll high)
{
    while (low < high)
    {
        ll mid = (high + low) / 2;
        if (check(mid))
            high = mid;
        else
            low = mid + 1;
    }

    print(high);
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        ll sum = 0;
        cin >> n >> k;
        int cmin = inf;
        arr.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
            cmin = min(cmin, arr[i]);
        }
        binary(cmin, sum);
        arr.clear();

    }
    // fclose(stdin);
    return 0;
}