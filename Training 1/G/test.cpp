#include <bits/stdc++.h>
using namespace std;
int t;
int A[30];
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for(int i = 0; i <= 25; i++)
    {
        if(i%3 == 0) A[i] = 1;
        if(i%3 == 1) A[i] = 2;
        if(i%3 == 2) A[i] = 3;
    }
    A['s'- 'a'] = 4;
    //tuv   wxyz
    A['t'- 'a'] = 1;
    A['u'- 'a'] = 2;
    A['v'- 'a'] = 3;
    A['w'- 'a'] = 1;
    A['x'- 'a'] = 2;
    A['y'- 'a'] = 3;
    A['z'- 'a'] = 4;
    // for(int i = 0; i<= 25; i++)
    //     cout << char('a' + i) <<" " << A[i] <<"\n";

    cin >> t;
    char c = getchar();
    for(int i = 1; i <= t; i ++)
    {
        string s;
        getline(cin, s);
        //cout << s << endl;
        int res = 0;
        //cout << s.size() << endl;
        for(int j = 0 ; j < s.size(); j ++)
        {
            if(s[j] == ' ') res++;
            else
            {
                res = res + A[s[j] - 'a'];
            }
        }
        
        cout <<"Case #" << i <<": " << res <<"\n";
    }
    fclose(stdin);
    fclose(stdout);
}
