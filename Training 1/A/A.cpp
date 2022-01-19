#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    
    ifstream f ("input.txt");
    f >> a >> b;
    while(a.size() > b.size()) b = "0" + b;
    while(a.size() < b.size()) a = "0" + a;
    int ln = a.size();
    int nho = 0;
    string res;
    for(int i = ln -1; i >=0; i--){
        int tmp = (a[i] -'0') + (b[i] - '0') + nho;
        nho = tmp / 10;
        tmp = tmp % 10;
        char c = tmp + '0';
        res = c + res;
    }
    if(nho == 1) res = "1" + res;
    cout<<res;
}
