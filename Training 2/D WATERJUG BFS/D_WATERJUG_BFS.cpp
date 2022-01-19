#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b==0)
       return a;
    return gcd(b, a%b);
}
int pour(int fromCap, int toCap, int d)
{
    // Initialize current amount of water
    // in source and destination jugs
    int from = fromCap;
    int to = 0;
 
    // Initialize count of steps required
    int step = 1; // Needed to fill "from" Jug
 
    // Break the loop when either of the two
    // jugs has d litre water
    while (from != d && to != d)
    {
        // Find the maximum amount that can be
        // poured
        int temp = min(from, toCap - to);
 
        // Pour "temp" liters from "from" to "to"
        to   += temp;
        from -= temp;
 
        // Increment count of steps
        step++;
 
        if (from == d || to == d)
            break;
 
        // If first jug becomes empty, fill it
        if (from == 0)
        {
            from = fromCap;
            step++;
        }
 
        // If second jug becomes full, empty it
        if (to == toCap)
        {
            to = 0;
            step++;
        }
    }
    return step;
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a < b){
        swap(a,b);
    }
    if(c % gcd(a,b) != 0){
        cout << -1;
    }
    else{
        int res1 = pour(a,b,c);
        int res2 = pour(b,a,c);
        cout << min(res1, res2);
    }
}