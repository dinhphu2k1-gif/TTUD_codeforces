#include <bits/stdc++.h>

using namespace std;
#define P (1000000000+7)
int a[1001][1001];
int k, n;

int C(int k, int n)
{
	if (k == n || k == 0) return 1;
	if (k == 1) return n;
	if (a[k][n] == 0)
	    a[k][n] = C(k - 1, n - 1) + C(k, n - 1);
	return a[k][n] % P;
}

int main(){
    cin >> k >> n;
    cout << C(k, n);
    return 0;
}